#pragma once

namespace Onyx
{
	// 2 component vector. Suitable for 2D games
	// Z is constant and set to 0.0
	struct ONYX_API Vector2
	{
		Vector2(float x, float y) :
			X(x), Y(y) { }

		float operator*(Vector2 v1) { return (X * v1.X) + (Y * v1.Y); }
		Vector2 operator+(Vector2 v1) { return { X + v1.X, Y + v1.Y }; }
		Vector2 operator-(Vector2 v1) { return { X - v1.X, Y - v1.Y }; }
		Vector2 operator/(float value) { return { X / value, Y / value }; }

		// Add another Vector2
		// Overwrites the values in vector
		inline void Add(Vector2 v1) { X += v1.X; Y += v1.Y; }

		float Length() { return sqrt((*this) * (*this)); }

		inline Vector2 Normalize(float value) { return (*this) / Length(); }

		float X, Y;
		const float Z = 0.0f;
	};

		// 3 component vector
		// Suitable for 2.5D and 3D games
	struct ONYX_API Vector3
	{
		Vector3(float x, float y, float z) :
			X(x), Y(y), Z(z) { }
		Vector3 operator+(Vector3 v1) { return { X + v1.X, Y + v1.Y, Z + v1.Z }; }
		Vector3 operator-(Vector3 v1) { return { X - v1.X, Y - v1.Y, Z - v1.Z }; }
		// Returns a dot product of 2 vectors
		float operator*(Vector3 v1) { return(X * v1.X) + (Y * v1.Y) + (Z * v1.Z); }
		Vector3 operator/(float value) { return { X / value, Y / value, Z / value }; }

		// Add another Vector3
		// Overwrites the values in Vector
		inline void Add(Vector3 v1) { X += v1.X; Y += v1.Y; Z += v1.Z; }

		float Length() { return sqrt((*this) * (*this)); }

		inline Vector3 Normalize(float value) { return (*this) / Length(); }

		float X, Y, Z;
	};
}