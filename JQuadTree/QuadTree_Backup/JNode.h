#pragma once
#include"JObject.h"

class JNode{
public:
	JRact m_Rect;
	JNode* m_pParent;
	int m_iDepth;
	JNode* m_Child[4];
	int m_iIndex;
	std::vector<JVector2> m_ObjectList;
	std::map<std::string,JObject*> m_Dynamic_ObjectList;

public:
	JNode() {};
	JNode(JNode* p_Parent, float fX, float fY, float fWidth, float fHeight, int iDepth, int iIndex);
};

