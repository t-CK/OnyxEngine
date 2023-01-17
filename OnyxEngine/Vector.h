#pragma once



struct Vector2
{
	Vector2(float x, float y) :
		X(x), Y(y) { }

	float operator*(Vector2 v1) { return (X * v1.X) + (Y * v1.Y); }
	Vector2 operator+(Vector2 v1) { return { X + v1.X, Y + v1.Y }; }
	Vector2 operator-(Vector2 v1) { return { X - v1.X, Y - v1.Y }; }

	// Add another Vector2
	// Overwrites the values in vector
	void Add(Vector2 v1) { X += v1.X; Y += v1.Y; }

	// X, Y and Z components of vector
	// Z is set to 0 by default for 2D graphics
	float X, Y;
	const float Z = 0.0f;
};

struct Vector3
{
	Vector3(float x, float y, float z) :
		X(x), Y(y), Z(z) { }
	Vector3 operator+(Vector3 v1) { return { X + v1.X, Y + v1.Y, Z + v1.Z }; }
	Vector3 operator-(Vector3 v1) { return { X - v1.X, Y - v1.Y, Z - v1.Z }; }
	// Returns a dot product of 2 vectors
	float operator*(Vector3 v1) { return(X * v1.X) + (Y * v1.Y) + (Z * v1.Z); }

	// Add another Vector3
	// Overwrites the values in Vector
	void Add(Vector3 v1) { X += v1.X; Y += v1.Y; Z += v1.Z; }

	float X, Y, Z;
};
