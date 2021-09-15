#include"JNode.h"
#define MAXSIZE 4

class JQuadTree{
public:
	JNode *m_pRootNode;
	std::map<std::string, JObject*> m_Dynamic_ObjectAllList;
	std::queue<JNode*> m_Queue;
public:
	float m_iWidth;
	float m_iHeight;
	static int g_newCounter;


public:
	void Init(float fWidth, float fHeight);
	JNode* CreateNode(JNode* p_Parent, float fX, float fY, float fWidth, float fHeight, int iDepth);
	void BuildTree(JNode* pNode);
	JNode* FindNode(JNode* pNode, JVector2 pos);
	JNode* FindPlayerNode(JNode* pNode, JVector2 pos,std::string);
	void AddObject(JVector2 pos);
	void AddObject(JObject *player);
	JNode* FindIndexNode(int &iIndex);
	JNode* FindIndexQueue(JNode* pNode, int& iIndex);

	JNode* Preorder(JNode* pNode, int& iIndex);
	void Frame(JObject* Target, float fTime);

	bool isRact(JNode* pNode, JVector2 pos);

public:
	JQuadTree() : m_pRootNode(nullptr),m_iHeight(NULL),m_iWidth(NULL) {};
	//JQuadTree(JNode*, float, float);
};