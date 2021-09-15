#include "JNode.h"


JNode::JNode(JNode* pParent, float fX, float fY, float fWidth, float fHeight, int iDepth,int iIndex){
	this->m_Rect.wh = JVector2(fWidth, fHeight);
	this->m_Rect.p0 = JVector2(fX, fY);
	this->m_Rect.p1 = this->m_Rect.p0 + this->m_Rect.wh;
	
	this->m_iDepth = iDepth;
	this->m_pParent = pParent;
	this->m_iIndex = iIndex;
	

}

