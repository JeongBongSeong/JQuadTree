
struct JVector2
{
	float x;
	float y;

public:
	JVector2() : x(0.0f), y(0.0f) {};		// 초기화
	JVector2(float, float);					// 초기화
	JVector2	operator +	(JVector2);		// 벡터 더하기
	JVector2	operator +=	(JVector2);		// 벡터 더하기
	JVector2	operator -	(JVector2);		// 벡터 빼기
	float		operator |	(JVector2);		// 벡터 내적
	//JVector2	operator +	(JVector2);		//


};


