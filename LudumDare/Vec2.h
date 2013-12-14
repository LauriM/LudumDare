#ifndef ENGINE_MATH_VECTOR_H
#define ENGINE_MATH_VECTOR_H

template <typename T>
class Vec2{
	public:
		typedef typename T Type;

		Vec2()
			:x()
			,y()
		{}

		Vec2(Type x, Type y)
			:x(x)
			,y(y)
		{}

		union{
			struct { Type x,y; };
			Type v[2];
		};

		Vec2 operator - (const Vec2 &src) { return Vec2(*this) -= src; }
		Vec2 operator + (const Vec2 &src) { return Vec2(*this) += src; }
		Vec2 operator * (const Type &src) { return Vec2(*this) *= src; }
		Vec2 operator / (const Type &src) { return Vec2(*this) /= src; }

		const Vec2 &operator /=(Type value){
			x /= value;
			y /= value;
			return *this;
		}

		const Vec2 &operator *=(Type value){
			x *= value;
			y *= value;
			return *this;
		}

		const Vec2 &operator -=(Vec2 value){
			x -= value.x;
			y -= value.y;
			return *this;
		}

		const Vec2 &operator +=(Vec2 value){
			x += value.x;
			y += value.y;
			return *this;
		}

		inline Type getDotProduct(const Vec2 &other) const {
			Type ret = T();
			ret = (x * other.x) + (y * other.y);

			return ret;
		}

		inline Type getSquareLenght(){
			return x * x + y * y;
		} 

		inline float getLenght(){
			return std::sqrt(getSquareLenght());
		}

		inline const Vec2 &normalize(){
			return *this /= getLenght();
		}

		inline const Vec2 getNormalized() const { //TODO: doesnt work or wtf (2013-03-14)
			return this.normalize();
		}

		inline float getAngle(){
			return std::atan2(y,x);
		}

		inline const Vec2 getCrossProduct(){
			return Vec2<T>(y,-x);
		}

		inline void rotate(T angle)
		{

		}
};

#endif