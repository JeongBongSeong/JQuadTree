#include"JStd.h"
#include <math.h>
struct JVector2
{
	float x;
	float y;

public:
	JVector2() : x(0.0f), y(0.0f) {};		// �ʱ�ȭ
	JVector2(float, float);					// �ʱ�ȭ
	JVector2	operator +	(JVector2);		// ���� ���ϱ�
	JVector2	operator +=	(JVector2);		// ���� ���ϱ�
	JVector2	operator -	(JVector2);		// ���� ����
	JVector2	operator *	(float);
	float		operator |	(JVector2);		// ���� ����
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
