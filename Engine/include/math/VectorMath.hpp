//
// VectorMath.hpp
// openvox Engine
//
// Created by Benjamin Arnold on 29 Aug 2015
//

/*! \file VectorMath.hpp
* @brief defines common vector math operations.
*/

#pragma once

namespace openvox {
    namespace math {
        /*! @brief Computes the dot product of two vectors.
        */
        template <typename T>
        inline T dot(const Vector2<T>& v1, const Vector2<T>& v2) {
            static_assert(std::numeric_limits<T>::is_iec559, "dot only accepts floating-point inputs.");
            return v1.x * v2.x + v1.y * v2.y;
        }
        template <typename T>
        inline T dot(const Vector3<T>& v1, const Vector3<T>& v2) {
            static_assert(std::numeric_limits<T>::is_iec559, "dot only accepts floating-point inputs.");
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        }
        template <typename T>
        inline T dot(const Vector4<T>& v1, const Vector4<T>& v2) {
            static_assert(std::numeric_limits<T>::is_iec559, "dot only accepts floating-point inputs.");
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
        }
        /*! @brief Gets the length of a vector.
        */
        template <typename T>
        inline T length(const Vector2<T>& v) {
            return openvox::math::sqrt(v.x * v.x + v.y * v.y);
        }
        template <typename T>
        inline T length(const Vector3<T>& v) {
            return openvox::math::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        }
        template <typename T>
        inline T length(const Vector4<T>& v) {
            return openvox::math::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
        }
        /*! @brief Gets the squared length of a vector. Is faster than getting length.
        */
        template <typename T>
        inline T lengthSquared(const Vector2<T>& v) {
            return v.x * v.x + v.y * v.y;
        }
        template <typename T>
        inline T lengthSquared(const Vector3<T>& v) {
            return v.x * v.x + v.y * v.y + v.z * v.z;
        }
        template <typename T>
        inline T lengthSquared(const Vector4<T>& v) {
            return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
        }
        /*! @brief Computes the cross product of two 3d vectors.
        */
        template <typename T>
        inline Vector3<T> cross(const Vector3<T>& v1, const Vector3<T>& v2) {
            static_assert(std::numeric_limits<T>::is_iec559, "cross only accepts floating-point inputs.");
            return Vector3<T>(v1.y * v2.z - v1.z * v2.y,
                              v1.z * v2.x - v1.x * v2.z,
                              v1.x * v2.y - v1.y * v2.x);
        }
        /*! @brief Normalizes a vector, turning it into a unit vector.
        */
        template <typename T>
        inline Vector2<T> normalize(const Vector2<T>& v) {
#ifdef OPENVOX_MATH_FAST
            return v * openvox::math::fastInverseSqrt(lengthSquared(v));
#else
            return v / openvox::math::length(v);
#endif
        }
        template <typename T>
        inline Vector3<T> normalize(const Vector3<T>& v) {
#ifdef OPENVOX_MATH_FAST
            return v * openvox::math::fastInverseSqrt(lengthSquared(v));
#else
            return v / openvox::math::length(v);
#endif
        }
        template <typename T>
        inline Vector4<T> normalize(const Vector4<T>& v) {
#ifdef OPENVOX_MATH_FAST
            return v * openvox::math::fastInverseSqrt(lengthSquared(v));
#else
            return v / openvox::math::length(v);
#endif
        }

        // Basic function calls
#define VEC_FCALL(name, func) \
        template <typename T> \
        inline Vector2<T> name(const Vector2<T>& v) { \
            return Vector2<T>(func(v.x), func(v.y)); \
                } \
        template <typename T> \
        inline Vector3<T> name(const Vector3<T>& v) { \
            return Vector3<T>(func(v.x), func(v.y), func(v.z)); \
                } \
        template <typename T> \
        inline Vector4<T> name(const Vector4<T>& v) { \
            return Vector4<T>(func(v.x), func(v.y), func(v.z), func(v.w)); \
                }

        VEC_FCALL(sin, std::sin);
        VEC_FCALL(cos, std::cos);
        VEC_FCALL(tan, std::tan);
        VEC_FCALL(acos, std::acos);
        VEC_FCALL(asin, std::asin);
        VEC_FCALL(atan, std::atan);
        VEC_FCALL(abs, openvox::math::abs);
        VEC_FCALL(floor, openvox::math::floor);
        VEC_FCALL(ceil, openvox::math::ceil);
        VEC_FCALL(trunc, openvox::math::trunc);
        VEC_FCALL(round, openvox::math::round);
        VEC_FCALL(fract, openvox::math::fract);
        VEC_FCALL(sign, openvox::math::sign);
        VEC_FCALL(radians, openvox::math::radians);
        VEC_FCALL(degrees, openvox::math::degrees);
        VEC_FCALL(sqrt, openvox::math::sqrt);
        VEC_FCALL(exp, openvox::math::exp);
        VEC_FCALL(exp2, openvox::math::exp2);
        VEC_FCALL(log, openvox::math::log);
        VEC_FCALL(log2, openvox::math::log2);
#undef VEC_FCALL

        template <typename T>
        inline Vector2<T> mod(const Vector2<T>& v, T a) {
            return Vector2<T>(openvox::math::mod(v.x, a), openvox::math::mod(v.y, a));
        }
        template <typename T>
        inline Vector3<T> mod(const Vector3<T>& v, T a) {
            return Vector3<T>(openvox::math::mod(v.x, a), openvox::math::mod(v.y, a), openvox::math::mod(v.z, a));
        }
        template <typename T>
        inline Vector4<T> mod(const Vector4<T>& v, T a) {
            return Vector4<T>(openvox::math::mod(v.x, a), openvox::math::mod(v.y, a), openvox::math::mod(v.z, a), openvox::math::mod(v.w, a));
        }

        template <typename T>
        inline Vector2<T> min(const Vector2<T>& v1, const Vector2<T>& v2) {
            return Vector2<T>(openvox::math::min(v1.x, v2.x), openvox::math::min(v1.y, v2.y));
        }
        template <typename T>
        inline Vector3<T> min(const Vector3<T>& v1, const Vector3<T>& v2) {
            return Vector3<T>(openvox::math::min(v1.x, v2.x), openvox::math::min(v1.y, v2.y), openvox::math::min(v1.z, v2.z));
        }
        template <typename T>
        inline Vector4<T> min(const Vector4<T>& v1, const Vector4<T>& v2) {
            return Vector4<T>(openvox::math::min(v1.x, v2.x), openvox::math::min(v1.y, v2.y), openvox::math::min(v1.z, v2.z), openvox::math::min(v1.w, v2.w));
        }

        template <typename T>
        inline Vector2<T> max(const Vector2<T>& v1, const Vector2<T>& v2) {
            return Vector2<T>(openvox::math::max(v1.x, v2.x), openvox::math::max(v1.y, v2.y));
        }
        template <typename T>
        inline Vector3<T> max(const Vector3<T>& v1, const Vector3<T>& v2) {
            return Vector3<T>(openvox::math::max(v1.x, v2.x), openvox::math::max(v1.y, v2.y), openvox::math::max(v1.z, v2.z));
        }
        template <typename T>
        inline Vector4<T> max(const Vector4<T>& v1, const Vector4<T>& v2) {
            return Vector4<T>(openvox::math::max(v1.x, v2.x), openvox::math::max(v1.y, v2.y), openvox::math::max(v1.z, v2.z), openvox::math::max(v1.w, v2.w));
        }

        template <typename T>
        inline Vector2<T> clamp(const Vector2<T>& v, T minVal, T maxVal) {
            return Vector2<T>(openvox::math::clamp(v.x, minVal, maxVal), openvox::math::clamp(v.y, minVal, maxVal));
        }
        template <typename T>
        inline Vector3<T> clamp(const Vector3<T>& v, T minVal, T maxVal) {
            return Vector3<T>(openvox::math::clamp(v.x, minVal, maxVal), openvox::math::clamp(v.y, minVal, maxVal), openvox::math::clamp(v.z, minVal, maxVal));
        }
        template <typename T>
        inline Vector4<T> clamp(const Vector4<T>& v, T minVal, T maxVal) {
            return Vector4<T>(openvox::math::clamp(v.x, minVal, maxVal), openvox::math::clamp(v.y, minVal, maxVal), openvox::math::clamp(v.z, minVal, maxVal), openvox::math::clamp(v.w, minVal, maxVal));
        }
    }
}
namespace openvoxm = openvox::math;

#endif // !OpenVox_VectorMath_hpp__
