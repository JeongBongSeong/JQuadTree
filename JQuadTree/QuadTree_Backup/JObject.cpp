#include "JObject.h"

JObject::JObject(){
	m_Pos = JVector2(0.0f, 0.0f);
	this->m_fAcceleration.x = 1.0f;
	this->m_fMass = 1;
}

void JObject::Init(std::string sName, float fX,float fY, float fForceX, float fForceY,float fMass)
{
	this->m_sName = sName;
	this->m_Pos = JVector2(fX, fY);
	this->m_Force = JVector2(fForceX, fForceY);
	this->m_fMass = fMass;
	this->m_fAcceleration.x = fForceX / fMass;
	this->m_fAcceleration.y = fForceY / fMass;

	
	this->m_Velocity = JVector2(0.0f, 0.0f);
	this->iIndexNode = NULL;
}
