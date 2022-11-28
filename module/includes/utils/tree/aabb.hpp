#pragma once

#include "utils/Vector2.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <deque>
#include <limits>
#include <memory_resource>
#include <optional>
#include <ostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace sw 
{
    namespace tree {

    using maybe_index = std::optional<std::size_t>;

    template<typename T>
    concept Numeric = std::is_arithmetic<T>::value;

    template <typename T>
    class aabb final
    {
    public:
        using value_type = T;
        using vector_type = Vector2<value_type>;

        constexpr aabb() noexcept = default;
        constexpr aabb(const vector_type min, const vector_type max)
            : m_min{ min },
            m_max{ max },
            m_area{ compute_area() }
        {
            if ((m_min.x > m_max.x) || (m_min.y > m_max.y)) {
                throw std::invalid_argument("AABB: min > max");
            }
        }

        constexpr void update_area() noexcept
        {
            m_area = compute_area();
        }

        constexpr void fatten(const std::optional<double> factor)
        {
            if (!factor) {
                return;
            }

            const auto size = m_max - m_min;
            const auto dx = *factor * size.x;
            const auto dy = *factor * size.y;

            m_min.x -= dx;
            m_min.y -= dy;

            m_max.x += dx;
            m_max.y += dy;

            m_area = compute_area();
        }

        [[nodiscard]] static auto merge(const aabb& fst, const aabb& snd) -> aabb
        {
            vector_type lower;
            vector_type upper;

            lower.x = std::min(fst.m_min.x, snd.m_min.x);
            upper.x = std::max(fst.m_max.x, snd.m_max.x);
            lower.y = std::min(fst.m_min.y, snd.m_min.y);
            upper.y = std::max(fst.m_max.y, snd.m_max.y);

            return aabb{ lower, upper };
        }

        [[nodiscard]] constexpr auto contains(const aabb& other) const noexcept
            -> bool
        {
            if (other.m_min.x < m_min.x && other.m_min.y < m_min.y) {
                return false;
            }
            if (other.m_max.x > m_max.x && other.m_max.y > m_max.y) {
                return false;
            }
            return true;
        }

        [[nodiscard]] constexpr auto overlaps(const aabb& other,
            bool touchIsOverlap) const noexcept
            -> bool
        {
            if (touchIsOverlap) 
            {
                if ((other.m_max.x < m_min.x || other.m_min.x > m_max.x) || (other.m_max.y < m_min.y || other.m_min.y > m_max.y))
                {
                    return false;
                }
            } else 
            {
                if ((other.m_max.x <= m_min.x || other.m_min.x >= m_max.x) || (other.m_max.y <= m_min.y || other.m_min.y >= m_max.y))
                {
                    return false;
                }
            }

            return true;
        }

        [[nodiscard]] constexpr auto compute_area() const noexcept -> double
        {
            auto sum = 0.0;

            auto product = 1.0;

            auto dy = m_max.y - m_min.y;
            product *= dy;
            sum += product;
            dy = m_max.x - m_min.x;
            sum += product;

            return 2.0 * sum;
        }

        [[nodiscard]] constexpr auto area() const noexcept -> double
        {
            return m_area;
        }

        [[nodiscard]] constexpr auto size() const noexcept -> vector_type
        {
            return m_max - m_min;
        }

        [[nodiscard]] constexpr auto min() const noexcept -> const vector_type&
        {
            return m_min;
        }

        [[nodiscard]] constexpr auto max() const noexcept -> const vector_type&
        {
            return m_max;
        }

    private:
        vector_type m_min;
        vector_type m_max;
        double m_area{};
    };

    template <typename T> aabb(Vector2<T>, Vector2<T>)->aabb<T>;

    template <typename T>
    [[nodiscard]] constexpr auto operator==(const aabb<T>& lhs,
        const aabb<T>& rhs) noexcept -> bool
    {
        return (lhs.min() == rhs.min()) && (lhs.max() == rhs.max());
    }

    template <typename T>
    [[nodiscard]] constexpr auto operator!=(const aabb<T>& lhs,
        const aabb<T>& rhs) noexcept -> bool
    {
        return !(lhs == rhs);
    }

    template <typename Key, typename T>
    struct node final
    {
        using key_type = Key;
        using aabb_type = aabb<T>;

        std::optional<key_type> id;
        aabb_type aabb;

        maybe_index parent;
        maybe_index left;
        maybe_index right;
        maybe_index next;
        int height{ -1 };

        [[nodiscard]] auto is_leaf() const noexcept -> bool
        {
            return left == std::nullopt;
        }
    };

    template <Numeric Key, Numeric T = double>
    class tree final
    {
        template <typename U>
        using pmr_stack = std::stack<U, std::pmr::deque<U>>;

    public:
        using value_type = T;
        using key_type = Key;
        using vector_type = Vector2<value_type>;
        using aabb_type = aabb<value_type>;
        using node_type = node<key_type, value_type>;
        using size_type = std::size_t;
        using index_type = size_type;

        explicit tree(const size_type capacity = 16) : m_nodeCapacity{ capacity }
        {
            assert((m_root == std::nullopt));
            assert((m_nodeCount == 0));
            assert((m_nodeCapacity == capacity));

            resize_to_match_node_capacity(0);

            assert((m_nextFreeIndex == 0));
        }

        void insert(const key_type& key,
            const vector_type& lowerBound,
            const vector_type& upperBound)
        {
            assert(!m_indexMap.count(key));

            const auto nodeIndex = allocate_node();
            auto& node = m_nodes.at(nodeIndex);
            node.id = key;
            node.aabb = { lowerBound, upperBound };
            std::cout << "AABB insert: " << node.aabb.min() << " " << node.aabb.max() << std::endl;
            std::cout << "AABB insert: " << node.aabb.size() << std::endl;
            node.aabb.fatten(m_skinThickness);
            node.height = 0;

            insert_leaf(nodeIndex);
            m_indexMap.emplace(key, nodeIndex);
        }

        void erase(const key_type& key)
        {
            if (const auto it = m_indexMap.find(key); it != m_indexMap.end()) {
                const auto node = it->second;

                m_indexMap.erase(it);

                assert(node < m_nodeCapacity);
                assert(m_nodes.at(node).is_leaf());

                remove_leaf(node);
                free_node(node);
            }
        }

        void clear()
        {
            auto it = m_indexMap.begin();

            while (it != m_indexMap.end()) {
                const auto nodeIndex = it->second;

                assert(nodeIndex < m_nodeCapacity);
                assert(m_nodes.at(nodeIndex).is_leaf());

                remove_leaf(nodeIndex);
                free_node(nodeIndex);

                ++it;
            }

            m_indexMap.clear();
        }

        auto update(const key_type& key, aabb_type aabb, bool forceReinsert = false)
            -> bool
        {
            if (const auto it = m_indexMap.find(key); it != m_indexMap.end()) {
                const auto nodeIndex = it->second;

                assert(nodeIndex < m_nodeCapacity);
                assert(m_nodes.at(nodeIndex).is_leaf());

                if (!forceReinsert && m_nodes.at(nodeIndex).aabb.contains(aabb)) {
                    return false;
                }

                remove_leaf(nodeIndex);
                aabb.fatten(m_skinThickness);

                auto& node = m_nodes.at(nodeIndex);
                node.aabb = aabb;
                node.aabb.update_area();

                insert_leaf(nodeIndex);

                return true;
            }
            else {
                return false;
            }
        }

        auto update(const key_type& key,
            const vector_type& lowerBound,
            const vector_type& upperBound,
            bool forceReinsert = false) -> bool
        {
            return update(key, { lowerBound, upperBound }, forceReinsert);
        }

        auto relocate(const key_type& key,
            const vector_type& position,
            bool forceReinsert = false) -> bool
        {
            if (const auto it = m_indexMap.find(key); it != m_indexMap.end()) {
                const auto& aabb = m_nodes.at(it->second).aabb;
                std::cout << "AABB relocate current position: " << aabb.min() << " " << aabb.max();
                std::cout << "AABB relocate size: " << aabb.size();
                std::cout << "AABB relocate new position: " << position;
                return update(key, { position, position + aabb.size() }, forceReinsert);
            }
            else {
                return false;
            }
        }

        void rebuild()
        {
            std::vector<index_type> nodeIndices(m_nodeCount);
            int count{ 0 };

            for (auto index = 0; index < m_nodeCapacity; ++index) {
                if (m_nodes.at(index).height < 0)
                    continue;

                if (m_nodes.at(index).is_leaf()) {
                    m_nodes.at(index).parent = std::nullopt;
                    nodeIndices.at(count) = index;
                    ++count;
                }
                else {
                    free_node(index);
                }
            }

            while (count > 1) {
                auto minCost = std::numeric_limits<double>::max();
                int iMin{ -1 };
                int jMin{ -1 };

                for (auto i = 0; i < count; ++i) {
                    const auto fstAabb = m_nodes.at(nodeIndices.at(i)).aabb;

                    for (auto j = (i + 1); j < count; ++j) {
                        const auto sndAabb = m_nodes.at(nodeIndices.at(j)).aabb;
                        const auto cost = aabb_type::merge(fstAabb, sndAabb).area();

                        if (cost < minCost) {
                            iMin = i;
                            jMin = j;
                            minCost = cost;
                        }
                    }
                }

                const auto index1 = nodeIndices.at(iMin);
                const auto index2 = nodeIndices.at(jMin);

                const auto parentIndex = allocate_node();
                auto& parentNode = m_nodes.at(parentIndex);

                auto& index1Node = m_nodes.at(index1);
                auto& index2Node = m_nodes.at(index2);

                parentNode.left = index1;
                parentNode.right = index2;
                parentNode.height = 1 + std::max(index1Node.height, index2Node.height);
                parentNode.aabb = aabb_type::merge(index1Node.aabb, index2Node.aabb);
                parentNode.parent = std::nullopt;

                index1Node.parent = parentIndex;
                index2Node.parent = parentIndex;

                nodeIndices.at(jMin) = nodeIndices.at(count - 1);
                nodeIndices.at(iMin) = parentIndex;
                --count;
            }

            m_root = nodeIndices.at(0);
        }

        void set_thickness_factor(std::optional<double> thicknessFactor)
        {
            if (thicknessFactor) {
                m_skinThickness = std::clamp(*thicknessFactor, 0.0, *thicknessFactor);
            }
            else {
                m_skinThickness = std::nullopt;
            }
        }

        template <size_type bufferSize = 256, typename OutputIterator>
        void query(key_type &ignore, Vector2f min, Vector2f max, OutputIterator iterator) const
        {
            /*
            auto same_aabb = [&min, &max](node_type node) 
                {
                    if (node.aabb.min() == min && node.aabb.max() == max)
                        return true;
                    return false;
                };
            if (const auto itnode = std::find_if(m_nodes.begin(), m_nodes.end(), same_aabb); itnode != m_nodes.end()) {
                const auto& sourceNode = *itnode;
            */
                std::array<std::byte, sizeof(maybe_index)* bufferSize> buffer;
                std::pmr::monotonic_buffer_resource resource{ buffer.data(),
                                                             sizeof buffer };
                aabb_type aabb_test(min, max);

                pmr_stack<maybe_index> stack{ &resource };
                stack.push(m_root);
                while (!stack.empty()) {
                    const auto nodeIndex = stack.top();
                    stack.pop();

                    if (!nodeIndex) {
                        continue;
                    }

                    const auto& node = m_nodes.at(*nodeIndex);

                    if (aabb_test.overlaps(node.aabb, m_touchIsOverlap)) {
                        if (node.is_leaf() && node.id) {
                            if (node.id != ignore)
                            {
                                *iterator = *node.id;
                                ++iterator;
                            }
                        }
                        else {
                            stack.push(node.left);
                            stack.push(node.right);
                        }
                    }
                }
            //}
        }

        template <size_type bufferSize = 256, typename OutputIterator>
        void query(const key_type& key, OutputIterator iterator) const
        {
            if (const auto it = m_indexMap.find(key); it != m_indexMap.end()) {
                const auto& sourceNode = m_nodes.at(it->second);

                std::array<std::byte, sizeof(maybe_index)* bufferSize> buffer;
                std::pmr::monotonic_buffer_resource resource{ buffer.data(),
                                                             sizeof buffer };

                pmr_stack<maybe_index> stack{ &resource };
                stack.push(m_root);
                while (!stack.empty()) {
                    const auto nodeIndex = stack.top();
                    stack.pop();

                    if (!nodeIndex) {
                        continue;
                    }

                    const auto& node = m_nodes.at(*nodeIndex);

                    if (sourceNode.aabb.overlaps(node.aabb, m_touchIsOverlap)) {
                        if (node.is_leaf() && node.id) {
                            if (node.id != key) {
                                *iterator = *node.id;
                                ++iterator;
                            }
                        }
                        else {
                            stack.push(node.left);
                            stack.push(node.right);
                        }
                    }
                }
            }
        }

        [[nodiscard]] auto get_aabb(const key_type& key) const -> const aabb_type&
        {
            return m_nodes.at(m_indexMap.at(key)).aabb;
        }

        [[nodiscard]] auto height() const -> int
        {
            if (m_root == std::nullopt) {
                return 0;
            }
            else {
                return m_nodes.at(*m_root).height;
            }
        }

        [[nodiscard]] auto node_count() const noexcept -> size_type
        {
            return m_nodeCount;
        }

        [[nodiscard]] auto size() const noexcept -> size_type
        {
            return m_indexMap.size();
        }

        [[nodiscard]] auto is_empty() const noexcept -> bool
        {
            return m_indexMap.empty();
        }

        [[nodiscard]] auto thickness_factor() const noexcept -> std::optional<double>
        {
            return m_skinThickness;
        }

    private:
        std::vector<node_type> m_nodes;
        std::unordered_map<key_type, index_type> m_indexMap;

        maybe_index m_root;
        maybe_index m_nextFreeIndex{ 0 };

        size_type m_nodeCount{ 0 };
        size_type m_nodeCapacity;

        std::optional<double> m_skinThickness{ 0.05 };

        bool m_touchIsOverlap{ false };

        void resize_to_match_node_capacity(const size_type beginInitIndex)
        {
            m_nodes.resize(m_nodeCapacity);
            for (auto i = beginInitIndex; i < (m_nodeCapacity - 1); ++i) {
                auto& node = m_nodes.at(i);
                node.next = static_cast<index_type>(i) + 1;
                node.height = -1;
            }

            auto& node = m_nodes.at(m_nodeCapacity - 1);
            node.next = std::nullopt;
            node.height = -1;
        }

        void grow_pool()
        {
            assert(m_nodeCount == m_nodeCapacity);

            m_nodeCapacity *= 2;
            resize_to_match_node_capacity(m_nodeCount);

            m_nextFreeIndex = static_cast<index_type>(m_nodeCount);
        }

        [[nodiscard]] auto allocate_node() -> index_type
        {
            if (m_nextFreeIndex == std::nullopt) {
                grow_pool();
            }

            const auto nodeIndex = m_nextFreeIndex.value();
            auto& node = m_nodes.at(nodeIndex);

            m_nextFreeIndex = node.next;
            node.parent = std::nullopt;
            node.left = std::nullopt;
            node.right = std::nullopt;
            node.height = 0;
            ++m_nodeCount;

            return nodeIndex;
        }

        void free_node(const index_type node)
        {
            assert(node < m_nodeCapacity);
            assert(0 < m_nodeCount);

            m_nodes.at(node).next = m_nextFreeIndex;
            m_nodes.at(node).height = -1;

            m_nextFreeIndex = node;
            --m_nodeCount;
        }

        [[nodiscard]] static auto left_cost(const aabb_type& leafAabb,
            const node_type& leftNode,
            const double minimumCost) -> double
        {
            if (leftNode.is_leaf()) {
                return aabb_type::merge(leafAabb, leftNode.aabb).area() + minimumCost;
            }
            else {
                const auto oldArea = leftNode.aabb.area();
                const auto newArea = aabb_type::merge(leafAabb, leftNode.aabb).area();
                return (newArea - oldArea) + minimumCost;
            }
        }

        [[nodiscard]] static auto right_cost(const aabb_type& leafAabb,
            const node_type& rightNode,
            const double minimumCost) -> double
        {
            if (rightNode.is_leaf()) {
                const auto aabb = aabb_type::merge(leafAabb, rightNode.aabb);
                return aabb.area() + minimumCost;
            }
            else {
                const auto aabb = aabb_type::merge(leafAabb, rightNode.aabb);
                const auto oldArea = rightNode.aabb.area();
                const auto newArea = aabb.area();
                return (newArea - oldArea) + minimumCost;
            }
        }

        [[nodiscard]] auto find_best_sibling(const aabb_type& leafAabb) const
            -> index_type
        {
            auto index = m_root.value();

            while (!m_nodes.at(index).is_leaf()) {
                const auto& node = m_nodes.at(index);
                const auto left = node.left.value();
                const auto right = node.right.value();

                const auto surfaceArea = node.aabb.area();
                const auto combinedSurfaceArea =
                    aabb_type::merge(node.aabb, leafAabb).area();

                const auto cost = 2.0 * combinedSurfaceArea;

                const auto minimumCost = 2.0 * (combinedSurfaceArea - surfaceArea);

                const auto costLeft = left_cost(leafAabb, m_nodes.at(left), minimumCost);
                const auto costRight =
                    right_cost(leafAabb, m_nodes.at(right), minimumCost);

                if ((cost < costLeft) && (cost < costRight)) {
                    break;
                }

                if (costLeft < costRight) {
                    index = left;
                }
                else {
                    index = right;
                }
            }

            return index;
        }

        [[nodiscard]] auto balance(const index_type nodeIndex) -> index_type
        {
            if (m_nodes.at(nodeIndex).is_leaf() || (m_nodes.at(nodeIndex).height < 2)) {
                return nodeIndex;
            }

            const auto leftIndex = m_nodes.at(nodeIndex).left.value();
            const auto rightIndex = m_nodes.at(nodeIndex).right.value();

            assert(leftIndex < m_nodeCapacity);
            assert(rightIndex < m_nodeCapacity);

            const auto currentBalance =
                m_nodes.at(rightIndex).height - m_nodes.at(leftIndex).height;

            if (currentBalance > 1) {
                rotate_right(nodeIndex, leftIndex, rightIndex);
                return rightIndex;
            }

            if (currentBalance < -1) {
                rotate_left(nodeIndex, leftIndex, rightIndex);
                return leftIndex;
            }

            return nodeIndex;
        }

        void fix_tree_upwards(maybe_index index)
        {
            while (index != std::nullopt) {
                index = balance(*index);

                auto& node = m_nodes.at(*index);

                const auto left = node.left.value();
                const auto right = node.right.value();

                const auto& leftNode = m_nodes.at(left);
                const auto& rightNode = m_nodes.at(right);

                node.height = 1 + std::max(leftNode.height, rightNode.height);
                node.aabb = aabb_type::merge(leftNode.aabb, rightNode.aabb);

                index = node.parent;
            }
        }

        void insert_leaf(const index_type leafIndex)
        {
            if (m_root == std::nullopt) {
                m_root = leafIndex;
                m_nodes.at(*m_root).parent = std::nullopt;
                return;
            }

            const auto leafAabb = m_nodes.at(leafIndex).aabb;
            const auto siblingIndex = find_best_sibling(leafAabb);

            const auto oldParentIndex = m_nodes.at(siblingIndex).parent;
            const auto newParentIndex = allocate_node();

            auto& newParent = m_nodes.at(newParentIndex);
            newParent.parent = oldParentIndex;
            newParent.aabb = aabb_type::merge(leafAabb, m_nodes.at(siblingIndex).aabb);
            newParent.height = m_nodes.at(siblingIndex).height + 1;

            if (oldParentIndex != std::nullopt) {
                auto& oldParent = m_nodes.at(*oldParentIndex);
                if (oldParent.left == siblingIndex) {
                    oldParent.left = newParentIndex;
                }
                else {
                    oldParent.right = newParentIndex;
                }
            }
            else {
                m_root = newParentIndex;
            }

            newParent.left = siblingIndex;
            newParent.right = leafIndex;

            m_nodes.at(siblingIndex).parent = newParentIndex;
            m_nodes.at(leafIndex).parent = newParentIndex;

            fix_tree_upwards(m_nodes.at(leafIndex).parent);
        }

        void adjust_ancestor_bounds(maybe_index index)
        {
            while (index != std::nullopt) {
                index = balance(*index);

                auto& node = m_nodes.at(*index);

                const auto left = node.left;
                const auto right = node.right;
                const auto& leftNode = m_nodes.at(left.value());
                const auto& rightNode = m_nodes.at(right.value());

                node.aabb = aabb_type::merge(leftNode.aabb, rightNode.aabb);
                node.height = 1 + std::max(leftNode.height, rightNode.height);

                index = node.parent;
            }
        }

        void remove_leaf(const index_type leafIndex)
        {
            if (leafIndex == m_root) {
                m_root = std::nullopt;
                return;
            }

            const auto parentIndex = m_nodes.at(leafIndex).parent;
            const auto grandParentIndex = m_nodes.at(parentIndex.value()).parent;

            const auto siblingIndex =
                (m_nodes.at(parentIndex.value()).left == leafIndex)
                ? m_nodes.at(parentIndex.value()).right
                : m_nodes.at(parentIndex.value()).left;

            if (grandParentIndex != std::nullopt) {
                if (m_nodes.at(*grandParentIndex).left == parentIndex) {
                    m_nodes.at(*grandParentIndex).left = siblingIndex;
                }
                else {
                    m_nodes.at(*grandParentIndex).right = siblingIndex;
                }

                m_nodes.at(siblingIndex.value()).parent = grandParentIndex;
                free_node(parentIndex.value());

                adjust_ancestor_bounds(grandParentIndex);
            }
            else {
                m_root = siblingIndex;
                m_nodes.at(siblingIndex.value()).parent = std::nullopt;
                free_node(parentIndex.value());
            }
        }

        void rotate_right(const index_type nodeIndex,
            const index_type leftIndex,
            const index_type rightIndex)
        {
            auto& node = m_nodes.at(nodeIndex);
            auto& rightNode = m_nodes.at(rightIndex);

            const auto rightLeft = rightNode.left.value();
            const auto rightRight = rightNode.right.value();

            assert(rightLeft < m_nodeCapacity);
            assert(rightRight < m_nodeCapacity);

            rightNode.left = nodeIndex;
            rightNode.parent = node.parent;
            node.parent = rightIndex;

            if (rightNode.parent != std::nullopt) {
                auto& rightParent = m_nodes.at(*rightNode.parent);
                if (rightParent.left == nodeIndex) {
                    rightParent.left = rightIndex;
                }
                else {
                    assert(rightParent.right == nodeIndex);
                    rightParent.right = rightIndex;
                }
            }
            else {
                m_root = rightIndex;
            }

            auto& leftNode = m_nodes.at(leftIndex);
            auto& rightRightNode = m_nodes.at(rightRight);
            auto& rightLeftNode = m_nodes.at(rightLeft);

            if (rightLeftNode.height > rightRightNode.height) {
                rightNode.right = rightLeft;
                node.right = rightRight;

                rightRightNode.parent = nodeIndex;

                node.aabb = aabb_type::merge(leftNode.aabb, rightRightNode.aabb);
                rightNode.aabb = aabb_type::merge(node.aabb, rightLeftNode.aabb);

                node.height = 1 + std::max(leftNode.height, rightRightNode.height);
                rightNode.height = 1 + std::max(node.height, rightLeftNode.height);
            }
            else {
                rightNode.right = rightRight;
                node.right = rightLeft;

                rightLeftNode.parent = nodeIndex;

                node.aabb = aabb_type::merge(leftNode.aabb, rightLeftNode.aabb);
                rightNode.aabb = aabb_type::merge(node.aabb, rightRightNode.aabb);

                node.height = 1 + std::max(leftNode.height, rightLeftNode.height);
                rightNode.height = 1 + std::max(node.height, rightRightNode.height);
            }
        }

        void rotate_left(const index_type nodeIndex,
            const index_type leftIndex,
            const index_type rightIndex)
        {
            auto& node = m_nodes.at(nodeIndex);
            auto& leftNode = m_nodes.at(leftIndex);

            const auto leftLeft = leftNode.left.value();
            const auto leftRight = leftNode.right.value();

            assert(leftLeft < m_nodeCapacity);
            assert(leftRight < m_nodeCapacity);

            leftNode.left = nodeIndex;
            leftNode.parent = node.parent;
            node.parent = leftIndex;

            if (leftNode.parent != std::nullopt) {
                auto& leftParent = m_nodes.at(*leftNode.parent);
                if (leftParent.left == nodeIndex) {
                    leftParent.left = leftIndex;
                }
                else {
                    assert(leftParent.right == nodeIndex);
                    leftParent.right = leftIndex;
                }
            }
            else {
                m_root = leftIndex;
            }

            auto& rightNode = m_nodes.at(rightIndex);
            auto& leftLeftNode = m_nodes.at(leftLeft);
            auto& leftRightNode = m_nodes.at(leftRight);

            if (leftLeftNode.height > leftRightNode.height) {
                leftNode.right = leftLeft;
                node.left = leftRight;

                leftRightNode.parent = nodeIndex;

                node.aabb = aabb_type::merge(rightNode.aabb, leftRightNode.aabb);
                leftNode.aabb = aabb_type::merge(node.aabb, leftLeftNode.aabb);

                node.height = 1 + std::max(rightNode.height, leftRightNode.height);
                leftNode.height = 1 + std::max(node.height, leftLeftNode.height);
            }
            else {
                leftNode.right = leftRight;
                node.left = leftLeft;

                leftLeftNode.parent = nodeIndex;

                node.aabb = aabb_type::merge(rightNode.aabb, leftLeftNode.aabb);
                leftNode.aabb = aabb_type::merge(node.aabb, leftRightNode.aabb);

                node.height = 1 + std::max(rightNode.height, leftLeftNode.height);
                leftNode.height = 1 + std::max(node.height, leftRightNode.height);
            }
        }
    };

}
}