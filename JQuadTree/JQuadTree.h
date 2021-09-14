#include"JStd.h"

class JQuadTree
{
public:
	JNode *m_pRootNode;
	JNode *m_Child[4];

public:
	float m_iWidth;
	float m_iHeight;

public:
	JQuadTree();
	JQuadTree(JNode*, float, float);
};