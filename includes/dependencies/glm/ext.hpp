/// @file glm/ext.hpp
///
/// @ref core (Dependence)
/// 
/// @defgroup gtc GTC Extensions (Stable)
///
/// @brief Functions and types that the GLSL specification doesn't define, but useful to have for a C++ program.
/// 
/// GTC extensions aim to be stable. 
/// 
/// Even if it's highly unrecommended, it's possible to include all the extensions at once by
/// including <glm/ext.hpp>. Otherwise, each extension needs to be included  a specific file.
/// 
/// @defgroup gtx GTX Extensions (Experimental)
/// 
/// @brief Functions and types that the GLSL specification doesn't define, but 
/// useful to have for a C++ program.
/// 
/// Experimental extensions are useful functions and types, but the development of
/// their API and functionality is not necessarily stable. They can change 
/// substantially between versions. Backwards compatibility is not much of an issue
/// for them.
/// 
/// Even if it's highly unrecommended, it's possible to include all the extensions 
/// at once by including <glm/ext.hpp>. Otherwise, each extension needs to be 
/// included  a specific file.

#pragma once

#include "glm.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_MESSAGE_EXT_INCLUDED_DISPLAYED)
#	define GLM_MESSAGE_EXT_INCLUDED_DISPLAYED
#	pragma message("GLM: All extensions included (not recommanded)")
#endif//GLM_MESSAGES

#include "dependencies/glm/gtc/bitfield.hpp"
#include "dependencies/glm/gtc/color_space.hpp"
#include "dependencies/glm/gtc/constants.hpp"
#include "dependencies/glm/gtc/epsilon.hpp"
#include "dependencies/glm/gtc/functions.hpp"
#include "dependencies/glm/gtc/integer.hpp"
#include "dependencies/glm/gtc/matrix_access.hpp"
#include "dependencies/glm/gtc/matrix_integer.hpp"
#include "dependencies/glm/gtc/matrix_inverse.hpp"
#include "dependencies/glm/gtc/matrix_transform.hpp"
#include "dependencies/glm/gtc/noise.hpp"
#include "dependencies/glm/gtc/packing.hpp"
#include "dependencies/glm/gtc/quaternion.hpp"
#include "dependencies/glm/gtc/random.hpp"
#include "dependencies/glm/gtc/reciprocal.hpp"
#include "dependencies/glm/gtc/round.hpp"
//#include "./gtc/type_aligned.hpp"
#include "dependencies/glm/gtc/type_precision.hpp"
#include "dependencies/glm/gtc/type_ptr.hpp"
#include "dependencies/glm/gtc/ulp.hpp"
#include "dependencies/glm/gtc/vec1.hpp"
#if GLM_HAS_ALIGNED_TYPE
#	include "dependencies/glm/gtc/type_aligned.hpp"
#endif

#include "dependencies/glm/gtx/associated_min_max.hpp"
#include "dependencies/glm/gtx/bit.hpp"
#include "dependencies/glm/gtx/closest_point.hpp"
#include "dependencies/glm/gtx/color_space.hpp"
#include "dependencies/glm/gtx/color_space_YCoCg.hpp"
#include "dependencies/glm/gtx/compatibility.hpp"
#include "dependencies/glm/gtx/component_wise.hpp"
#include "dependencies/glm/gtx/dual_quaternion.hpp"
#include "dependencies/glm/gtx/euler_angles.hpp"
#include "dependencies/glm/gtx/extend.hpp"
#include "dependencies/glm/gtx/extended_min_max.hpp"
#include "dependencies/glm/gtx/fast_exponential.hpp"
#include "dependencies/glm/gtx/fast_square_root.hpp"
#include "dependencies/glm/gtx/fast_trigonometry.hpp"
#include "dependencies/glm/gtx/gradient_paint.hpp"
#include "dependencies/glm/gtx/handed_coordinate_space.hpp"
#include "dependencies/glm/gtx/integer.hpp"
#include "dependencies/glm/gtx/intersect.hpp"
#include "dependencies/glm/gtx/log_base.hpp"
#include "dependencies/glm/gtx/matrix_cross_product.hpp"
#include "dependencies/glm/gtx/matrix_interpolation.hpp"
#include "dependencies/glm/gtx/matrix_major_storage.hpp"
#include "dependencies/glm/gtx/matrix_operation.hpp"
#include "dependencies/glm/gtx/matrix_query.hpp"
#include "dependencies/glm/gtx/mixed_product.hpp"
#include "dependencies/glm/gtx/norm.hpp"
#include "dependencies/glm/gtx/normal.hpp"
#include "dependencies/glm/gtx/normalize_dot.hpp"
#include "dependencies/glm/gtx/number_precision.hpp"
#include "dependencies/glm/gtx/optimum_pow.hpp"
#include "dependencies/glm/gtx/orthonormalize.hpp"
#include "dependencies/glm/gtx/perpendicular.hpp"
#include "dependencies/glm/gtx/polar_coordinates.hpp"
#include "dependencies/glm/gtx/projection.hpp"
#include "dependencies/glm/gtx/quaternion.hpp"
#include "dependencies/glm/gtx/raw_data.hpp"
#include "dependencies/glm/gtx/rotate_vector.hpp"

#include "dependencies/glm/gtx/spline.hpp"
#include "dependencies/glm/gtx/std_based_type.hpp"

#if !(GLM_COMPILER & GLM_COMPILER_CUDA)
#	include "dependencies/glm/gtx/string_cast.hpp"
#endif

#include "dependencies/glm/gtx/transform.hpp"
#include "dependencies/glm/gtx/transform2.hpp"
#include "dependencies/glm/gtx/vector_angle.hpp"
#include "dependencies/glm/gtx/vector_query.hpp"
#include "dependencies/glm/gtx/wrap.hpp"

#if GLM_HAS_TEMPLATE_ALIASES
#	include "dependencies/glm/gtx/scalar_multiplication.hpp"
#endif

#if GLM_HAS_RANGE_FOR
#	include "dependencies/glm/gtx/range.hpp"
#endif
