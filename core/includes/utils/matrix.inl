/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * matrix.inl
 *
 * Description:
 * Matrix functions implementation
 */

template<typename T>
sw::Matrix<T>& sw::Matrix<T>::operator=(const Matrix<T>& other)
{
    m_col = other.col();
    m_line = other.line();
    m_matrix.clear();
    for (unsigned ctr = 0; ctr < m_line; ctr += 1)
        m_matrix.push_back(std::vector<T>(other.m_matrix[ctr]));
    return (*this);
}

template <typename T>
sw::Matrix<T>& sw::Matrix<T>::operator*=(const T& right)
{
    for (unsigned line_ctr = 0; line_ctr < line(); line_ctr += 1)
        for (unsigned col_ctr = 0; col_ctr < col(); col_ctr += 1)
            m_matrix[line_ctr][col_ctr] *= right;
    return (*this);
}

template <typename T>
sw::Matrix<T> sw::Matrix<T>::operator*(const T& right)
{
    std::vector<std::vector<int>> result;

    for (unsigned line_ctr = 0; line_ctr < line(); line_ctr += 1) {
        result.push_back(std::vector<T>());
        for (unsigned col_ctr = 0; col_ctr < col(); col_ctr += 1) {
            result[line_ctr].push_back(0);
            result[line_ctr][col_ctr] = m_matrix[line_ctr][col_ctr] * right;
        }
    }
    return (sw::Matrix<T>(result));
}

template <typename T>
sw::Matrix<T>::Matrix(unsigned size)
{
    m_line = size;
    m_col = size;
    for (unsigned ctr = 0; ctr < m_line; ctr += 1)
        m_matrix.push_back(std::vector<T>(size, 0));
}

template <typename T>
sw::Matrix<T>::Matrix(unsigned col, unsigned line)
{
    m_line = line;
    m_col = col;
    for (unsigned ctr = 0; ctr < m_line; ctr += 1)
        m_matrix.push_back(std::vector<T>(col, 0));
}

template <typename T>
sw::Matrix<T>::Matrix(const sw::Matrix<T>& copy)
{
    m_line = copy.m_line;
    m_col = copy.m_col;
    for (unsigned ctr = 0; ctr < m_line; ctr += 1)
        m_matrix.push_back(std::vector<T>(copy.m_matrix[ctr]));
}

template <typename T>
sw::Matrix<T>::Matrix(const std::vector< std::vector<T> > array)
{
    m_line = array.size();
    m_col = array[0].size();
    for (unsigned ctr = 0; ctr < m_line; ctr += 1)
        m_matrix.push_back(std::vector<T>(array[ctr]));
}

template <typename T>
const std::vector< std::vector<T> >& sw::Matrix<T>::getMatrix() const
{
    return (m_matrix);
}

template <typename T>
void sw::Matrix<T>::setIdentity()
{
    if (m_col != m_line)
        return;
    for (unsigned line = 0; line < m_line; line += 1)
        for (unsigned col = 0; col < m_col; col += 1) {
            m_matrix[line][col] = 0;
            if (col == line)
                m_matrix[line][col] = 1;
        }
}

template<typename T>
unsigned sw::Matrix<T>::col() const
{
    return (m_col);
}

template<typename T>
unsigned sw::Matrix<T>::line() const
{
    return (m_line);
}

template <typename T>
inline sw::Matrix<T> operator*(const sw::Matrix<T>& left, const sw::Matrix<T>& right)
{
    std::vector<std::vector<T>> resultFlist;
    std::vector<std::vector<T>> leftFlist = left.getMatrix();
    std::vector<std::vector<T>> rightFlist = right.getMatrix();

    if (left.col() != right.line())
        return (sw::Matrix<T>(left));
    for (unsigned line_ctr = 0; line_ctr < left.line(); line_ctr += 1) {
        resultFlist.push_back(std::vector<T>());
        for (unsigned col_ctr = 0; col_ctr < right.col(); col_ctr += 1) {
            resultFlist[line_ctr].push_back(0);
            for (unsigned ctr = 0; ctr < left.col(); ctr += 1)
                resultFlist[line_ctr][col_ctr] += (leftFlist[line_ctr][ctr] * rightFlist[ctr][col_ctr]);
        }
    }
    return (sw::Matrix<T>(resultFlist));
}

template <typename T>
inline sw::Matrix<T> operator*=(sw::Matrix<T>& left, const sw::Matrix<T>& right)
{
    std::vector<std::vector<T>> resultFlist;
    std::vector<std::vector<T>> leftFlist = left.getMatrix();
    std::vector<std::vector<T>> rightFlist = right.getMatrix();

    if (left.col() != right.line())
        return (left);
    for (unsigned line_ctr = 0; line_ctr < left.line(); line_ctr += 1) {
        resultFlist.push_back(std::vector<T>());
        for (unsigned col_ctr = 0; col_ctr < right.col(); col_ctr += 1) {
            resultFlist[line_ctr].push_back(0);
            for (unsigned ctr = 0; ctr < left.col(); ctr += 1)
                resultFlist[line_ctr][col_ctr] += (leftFlist[line_ctr][ctr] * rightFlist[ctr][col_ctr]);
        }
    }
    sw::Matrix<T> result(resultFlist);
    left = result;
    return (left);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const sw::Matrix<T>& matrix)
{
    auto& vec = matrix.getMatrix();

    os << "Matrix<" << typeid(vec[0][0]).name() << "> :\n";
    for (int line = 0; line < matrix.line(); line += 1) {
        os << "\t[ ";
        for (int col = 0; col < matrix.col(); col += 1) {
            os << vec[line][col];
            if (col + 1 < matrix.col())
                os << " , ";
        }
        os << " ]\n";
    }
    return (os);
}