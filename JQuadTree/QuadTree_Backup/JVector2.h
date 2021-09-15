#include"JStd.h"
#include <math.h>
struct JVector2
{
	float x;
	float y;

public:
	JVector2() : x(0.0f), y(0.0f) {};		// √ ±‚»≠
	JVector2(float, float);					// √ ±‚»≠
	JVector2	operator +	(JVector2);		// ∫§≈Õ ¥ı«œ±‚
	JVector2	operator +=	(JVector2);		// ∫§≈Õ ¥ı«œ±‚
	JVector2	operator -	(JVector2);		// ∫§≈Õ ª©±‚
	JVector2	operator *	(float);
	float		operator |	(JVector2);		// ∫§≈Õ ≥ª¿˚
	//JVector2	operator +	(JVector2);		//


};

class JRact {
public:
	JVector2 p0;
	JVector2 p1;
	JVector2 wh;
public:
	JRact();
};
