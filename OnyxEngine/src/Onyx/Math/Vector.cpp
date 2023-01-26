#include "OnyxPch.h"
#include "Vector.h"

namespace Onyx
{
	Vector Vector::CrossProduct(Vector& v2)
	{
		float x, y, z;

		x = (Y * v2.Z) - (Z * v2.Y);
		y = (X * v2.Z) - (Z * v2.X);
		z = (X * v2.Y) - (Y * v2.X);

		return { x, y, z };
	}
}