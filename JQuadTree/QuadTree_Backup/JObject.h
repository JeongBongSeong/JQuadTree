#pragma once
#include"JVector2.h"

class JObject{
public:
	std::string m_sName;
	JVector2 m_Pos;
	JVector2 m_Force;
	JVector2 m_Velocity;
	float m_fMass;
	JVector2 m_fAcceleration;
	int iIndexNode;

public:
	JObject();
	void Init(std::string sName,float fX, float fY, float fForceX, float fForceY, float fMass);
};

