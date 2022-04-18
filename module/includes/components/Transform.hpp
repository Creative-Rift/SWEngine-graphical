/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Matrix.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_TRANSFORM_HPP
#define SWENGINE_OPENGLMODULE_TRANSFORM_HPP

#include "dependencies/glm/glm.hpp"

#include "base/Component.hpp"

#include "../OpenGLModule_Config.hpp"
#include "utils/Vector3.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Transform : public sw::Component
    {

        private:
            glm::mat4 m_matrix;                 // Matrix(4x4) for local transform
            glm::mat4 m_globalMatrix;           // Matrix(4x4) for global transform (include all parent)
            sw::Vector3f m_position;            // Local Position of the Entity
            sw::Vector3f m_globalPosition;      // Global position of the Entity (include all parent)
            sw::Vector3f m_scale;               // Local Scale of the Entity
            sw::Vector3f m_globalScale;         // Global Scale of the Entity (include all parent)
            float m_angle;                      // Rotation angle
            sw::Vector3f m_rotationAxis;        // Local Vector which define the axis rotation
            sw::Vector3f m_globalRotationAxis;  // Global Vector which define the axis rotation (include all parent)

            mutable bool m_needUpdate;         // Define if the transform need an update

            void needUpdate(bool value) {
                m_needUpdate = value;
            }
            ///
            /// Update the matrix.
            ///
            /// @warning The const is just to can use it in get method,
            /// It's modify m_matrix variable.
            ///
            /// Thanks to this, we can reduce the calculations to what
            /// is strictly necessary.
            void updateMatrix() noexcept ;

        public:
            ///
            /// Check if the Matrix need to be update.
            bool checkUpdate() const;

            ///
            /// Initialize a Matrix Component attached to the given Entity.
            ///
            /// @param entity The Entity to which the Matrix Component will
            /// be attached.
            explicit Transform(sw::GameObject& gameObject);

            ///
            /// Set the position of a Matrix Component.
            /// The default position of a Matrix Component is (0, 0).
            ///
            /// @warning This function overwrites the actual position.
            /// @see move() to add to the current position.
            ///
            /// @param position New position.
            void setPosition(const sw::Vector3f& position);

            /// Set the position of a Matrix Component.
            /// The default position of a Matrix Component is (0, 0).
            ///
            /// @warning This function overwrites the actual position.
            /// @see move() to add to the current position.
            ///
            /// @param x X coordinate of the new position.
            /// @param y Y coordinate of the new position.
            /// @param z Z coordinate of the new position.
            void setPosition(float x, float y, float z = 0);

            /// Move a Matrix Component
            ///
            /// @warning This function adds to the current position.
            /// @see setPosition to overwrite the actual position.
            ///
            /// @param offset Add to the actual position of
            /// the Matrix Component.
            void move(const sw::Vector3f& position);

            /// Move a Matrix Component.
            ///
            /// @warning This function adds to the current position.
            /// @see setPosition to overwrite the actual position.
            ///
            /// @param x X offset.
            /// @param y Y offset.
            /// @param z Z offset.
            void move(float x, float y, float z = 0);

            ///
            /// Get the position of a Matrix Component.
            const sw::Vector3f& getPosition() const noexcept;

            /// Get the globale position of a Matrix Component.
            const sw::Vector3f& getGlobalPosition() const noexcept;

            /// Set the scalation of a Matrix Component.
            /// The default scalation of a Matrix Component is (1, 1).
            ///
            /// @warning This function overwrites the actual scalation.
            /// @see scale() to add to the current scalation.
            ///
            /// @param scale New scalation.
            void setScale(const sw::Vector3f& scale);

            /// Set the scalation of a Matrix Component.
            /// The default scalation of a Matrix Component is (1, 1).
            ///
            /// @warning This function overwrites the actual scalation.
            /// @see scale() to add to the current scalation.
            ///
            /// @param x New horizontal scale factor.
            /// @param y New vertical scale factor.
            void setScale(float x, float y, float z = 1);

            /// Scale the Matrix Component.
            ///
            /// @warning This function multiplies the current scale of
            /// the Matrix Component.
            /// @see setScale() to overwrite the actual scalation.
            ///
            /// @param scale Scale factor.
            void scale(const sw::Vector3f& scale);

            /// Scale the Matrix Component.
            ///
            /// @warning This function multiplies the current scale of
            /// the Matrix Component.
            /// @see setScale() to overwrite the actual scalation.
            ///
            /// @param x scale factor for X axis.
            /// @param y scale factor for Y axis.
            /// @param z scale factor for Z axis.
            void scale(float x, float y, float z = 1);

            /// Get the scale of a Matrix Component.
            const sw::Vector3f& getScale() const noexcept;

            /// Get the global scale of a Matrix Component.
            const sw::Vector3f& getGlobalScale() const noexcept;

            /// Set the orientation of the Matrix Component.
            /// The default rotation of a Matrix Component is 0.
            ///
            /// @warning This function completely overwrites
            /// the previous rotation.
            /// @see rotate() to add an angle on the previous rotation.
            void setRotation(float angle, float rotationX = 0, float rotationY = 1, float rotationZ = 0);

            /// Rotate the Matrix Component.
            ///
            /// @warning This function adds to the current rotation of
            /// the Matrix Component.
            /// @see setRotation() to overwrite the actual orientation.
            void rotate(float angle, float rotationX = 0, float rotationY = 1, float rotationZ = 0);

            /// Get the orientation of the Matrix Component in degree.
            const sw::Vector3f& getRotationAxis() const noexcept;

            /// Get the orientation of the Matrix Component in degree.
            const float& getAngle() const noexcept;

            /// Get the global orientation of the Matrix Component in degree.
            const sw::Vector3f& getGlobalRotationAxis();

            /// Get the matrix of the Matrix Component.
            const glm::mat4& getMatrix() noexcept;

            /// Get the global matrix of the Matrix Component.
            const glm::mat4& getGlobalMatrix();

            /// Return the position of the given point, transform by
            /// the Matrix Component.
            /// @param point The point to transform.
            sw::Vector3f getTransformPoint(const sw::Vector3f& point);

            /// Return the position of the given point, transform by
            /// the Matrix Component.
            ///
            /// @param x X coordinate of the point to transform.
            /// @param y Y coordinate of the point to transform.
            sw::Vector3f getTransformPoint(float x, float y, float z = 1);

            /// Return the position of the given point, transform by
            /// the Matrix Component.
            ///
            /// @param point The point to transform.
            sw::Vector3f getGlobalTransformPoint(const sw::Vector3f& point);

            ///
            /// Return the position of the given point, transform by
            /// the Matrix Component.
            ///
            /// @param x X coordinate of the point to transform.
            /// @param y Y coordinate of the point to transform.
            sw::Vector3f getGlobalTransformPoint(float x, float y, float z = 1);


    }; // class Transform

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_TRANSFORM_HPP
