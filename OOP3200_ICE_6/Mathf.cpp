#include "Mathf.h"

#include <limits>

// math constants
const float Mathf::Epsilon = 0.00001f;
const float Mathf::EpsilonNormalSqrt = 1e-15f;
const float Mathf::PI = 3.141593f;
const float Mathf::Infinity = std::numeric_limits<float>::infinity();
const float Mathf::NegativeInfinity = -std::numeric_limits<float>::infinity();
const float Mathf::Deg2Rad = 0.01745329f;
const float Mathf::Rad2Deg = 57.29578f;

float Mathf::Sin(const float f)
{
	return static_cast<float>(sin(static_cast<double>(f)));
}

float Mathf::Cos(const float f)
{
	return static_cast<float>(cos(static_cast<double>(f)));
}

float Mathf::Tan(const float f)
{
	return static_cast<float>(tan(static_cast<double>(f)));
}

float Mathf::Asin(const float f)
{
	return static_cast<float>(asin(static_cast<double>(f)));
}

float Mathf::Acos(const float f)
{
	return static_cast<float>(acos(static_cast<double>(f)));
}

float Mathf::Atan(const float f)
{
	return static_cast<float>(atan(static_cast<double>(f)));
}

float Mathf::Atan2(const float y, const float x)
{
	return static_cast<float>(atan2(static_cast<double>(y), static_cast<double>(x)));
}

float Mathf::Sqrt(const float f)
{
	return static_cast<float>(sqrt(static_cast<double>(f)));
}

float Mathf::Abs(const float f)
{
	return abs(f);
}

int Mathf::Abs(int value)
{
	return abs(value);
}

float Mathf::Min(const float a, const float b)
{
	if (static_cast<double>(a) < static_cast<double>(b))
	{
		return a;
	}
	return b;
}

int Mathf::Min(const int a, const int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}

float Mathf::Max(const float a, const float b)
{
	if (static_cast<double>(a) > static_cast<double>(b))
	{
		return a;
	}
	return b;
}

int Mathf::Max(const int a, const int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

float Mathf::Pow(const float f, const float p)
{
	return static_cast<float>(pow(static_cast<double>(f), static_cast<double>(p)));
}

float Mathf::Exp(const float power)
{
	return static_cast<float>(exp(static_cast<double>(power)));
}

float Mathf::Log(const float f)
{
	return static_cast<float>(log(static_cast<double>(f)));
}

float Mathf::Log10(const float f)
{
	return static_cast<float>(log10(static_cast<double>(f)));
}

float Mathf::Ceil(const float f)
{
	return static_cast<float>(ceil(static_cast<double>(f)));
}

float Mathf::Floor(const float f)
{
	return static_cast<float>(floor(static_cast<double>(f)));
}

float Mathf::Round(const float f)
{
	return static_cast<float>(round(static_cast<double>(f)));
}

int Mathf::CeilToInt(const float f)
{
	return static_cast<int>(ceil(static_cast<double>(f)));
}

int Mathf::FloorToInt(const float f)
{
	return static_cast<int>(floor(static_cast<double>(f)));
}

int Mathf::RoundToInt(const float f)
{
	return static_cast<int>(round(static_cast<double>(f)));
}

float Mathf::Sign(const float f)
{
	return static_cast<double>(f) >= 0.0 ? 1.0f : -1.0f;
}

float Mathf::Clamp(float value, const float min, const float max)
{
	if (static_cast<double>(value) < static_cast<double>(min))
	{
		value = min;
	}
	else if (static_cast<double>(value) > static_cast<double>(max))
	{
		value = max;
	}
	return value;
}

int Mathf::Clamp(int value, const int min, const int max)
{
	if (value< min)
	{
		value = min;
	}	
	else if (value > max)
	{
		value = max;
	}
	return value;
}

float Mathf::Clamp01(const float value)
{
	if (static_cast<double>(value) < 0.0)
	{
		return 0.0f;
	}
	if (static_cast<double>(value) > 1.0)
	{
		return 1.0f;
	}	
	return value;
}

float Mathf::Lerp(const float a, const float b, const float t)
{
	return a + (b - a) * Mathf::Clamp01(t);
}

float Mathf::LerpUnclamped(const float a, const float b, const float t)
{
	return a + (b - a) * t;
}

float Mathf::LerpAngle(const float a, const float b, const float t)
{
	float num = Mathf::Repeat(b - a, 360.0f);
	if (static_cast<double>(num) > 180.0)
	{
		num -= 360.0f;
	}
	return a + num * Mathf::Clamp01(t);
}

float Mathf::MoveTowards(const float current, const float target, const float max_delta)
{
	if (static_cast<double>(Mathf::Abs(target - current)) <= static_cast<double>(max_delta))
	{
		return target;
	}	
	return current + Mathf::Sign(target - current) * max_delta;
}

float Mathf::MoveTowardsAngle(const float current, float target, const float max_delta)
{
	target = current + Mathf::DeltaAngle(current, target);
	return Mathf::MoveTowards(current, target, max_delta);
}

float Mathf::SmoothStep(const float from, const float to, float t)
{
	t = Mathf::Clamp01(t);
	t = static_cast<float>(-2.0 * static_cast<double>(t) * static_cast<double>(t) * static_cast<double>(t) + 3.0 * static_cast<double>(t) * static_cast<double>(t));
	return static_cast<float>(static_cast<double>(to) * static_cast<double>(t) + static_cast<double>(from) * (1.0 - static_cast<double>(t)));
}

bool Mathf::Approximately(const float a, const float b)
{
	return static_cast<double>(Mathf::Abs(b - a)) < static_cast<double>(Mathf::Max(1E-06f * Mathf::Max(Mathf::Abs(a), Mathf::Abs(b)), Mathf::Epsilon * 8.0f));
}

float Mathf::Repeat(const float t, const float length)
{
	return t - Mathf::Floor(t / length) * length;
}

float Mathf::PingPong(float t, const float length)
{
	t = Mathf::Repeat(t, length * 2.0f);
	return length - Mathf::Abs(t - length);
}

float Mathf::InverseLerp(const float a, const float b, const float value)
{
	if (static_cast<double>(a) != static_cast<double>(b))
	{
		return Mathf::Clamp01(static_cast<float>((static_cast<double>(value) - static_cast<double>(a)) / (static_cast<double>(b) - static_cast<
			double>(a))));
	}	
	return 0.0f;
}

float Mathf::DeltaAngle(const float current, const float target)
{
	float num = Mathf::Repeat(target - current, 360.0f);
	if (static_cast<double>(num) > 180.0)
	{
		num -= 360.0f;
	}
	return num;
}
