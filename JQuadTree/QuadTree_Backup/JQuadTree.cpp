#include"JQuadTree.h"

int JQuadTree::g_newCounter = 0;

void JQuadTree::Init(float fWidth, float fHeight){
	
	this->m_pRootNode = CreateNode(nullptr, 0, 0, fWidth, fHeight, g_newCounter);
	BuildTree(this->m_pRootNode);

}

JNode* JQuadTree::CreateNode(JNode* pParent, float fX, float fY, float fWidth, float fHeight, int iDepth){
	JNode* newNode = new JNode(pParent,fX,fY,fWidth,fHeight,iDepth,g_newCounter);
	g_newCounter++;
	return newNode;
}

void JQuadTree::BuildTree(JNode* pNode){
	//깊이가 2인 노드 포인터 변수가 들어올 경우 반환한다.
	if (pNode->m_iDepth == 2)
		return;

	// 0
	pNode->m_Child[0] = CreateNode(
		pNode,
		pNode->m_Rect.p0.x,
		pNode->m_Rect.p0.y,
		pNode->m_Rect.wh.x / 2.0f,
		pNode->m_Rect.wh.y / 2.0f,
		pNode->m_iDepth + 1
	);
	this->BuildTree(pNode->m_Child[0]);
	

	// 1
	pNode->m_Child[1] = CreateNode(
		pNode,
		pNode->m_Child[0]->m_Rect.p1.x,
		pNode->m_Child[0]->m_Rect.p0.y,
		pNode->m_Child[0]->m_Rect.wh.x,
		pNode->m_Child[0]->m_Rect.wh.y,
		pNode->m_iDepth + 1
	);
	this->BuildTree(pNode->m_Child[1]);
	

	// 2
	pNode->m_Child[2] = CreateNode(
		pNode,
		pNode->m_Child[0]->m_Rect.p0.x,
		pNode->m_Child[0]->m_Rect.p1.y,
		pNode->m_Child[0]->m_Rect.wh.x,
		pNode->m_Child[0]->m_Rect.wh.y,
		pNode->m_iDepth + 1
	);
	this->BuildTree(pNode->m_Child[2]);


	// 3
	pNode->m_Child[3] = CreateNode(
		pNode,
		pNode->m_Child[0]->m_Rect.p1.x,
		pNode->m_Child[0]->m_Rect.p1.y,
		pNode->m_Child[0]->m_Rect.wh.x,
		pNode->m_Child[0]->m_Rect.wh.y,
		pNode->m_iDepth + 1
	);
	this->BuildTree(pNode->m_Child[3]);


}

JNode* JQuadTree::FindNode(JNode* pNode, JVector2 TargetPos){
	
	if (pNode == nullptr)
		return pNode;

	// 자신 비교
	if (this->isRact(pNode, TargetPos)) {
		for (int i = 0; i < MAXSIZE; i++) {
			if (pNode->m_Child[i] == nullptr) {
				return pNode;
			}
			// 자식 비교
			if (this->isRact(pNode->m_Child[i], TargetPos)){
				return FindNode(pNode->m_Child[i], TargetPos);
			}
		}
		
		/*else if (this->isRact(m_pRootNode->m_Child[1], TargetPos)) {
			return FindNode(pNode->m_Child[1], TargetPos);
		}
		else if (this->isRact(m_pRootNode->m_Child[2], TargetPos)) {
			return FindNode(pNode->m_Child[2], TargetPos);
		}
		else if (this->isRact(m_pRootNode->m_Child[3], TargetPos)) {
			return FindNode(pNode->m_Child[3], TargetPos);
		}*/
	}
}

JNode* JQuadTree::FindPlayerNode(JNode* pNode, JVector2 TargetPos,std::string sName) {

	if (pNode == nullptr)
		return pNode;

	// 자신 비교
	if (this->isRact(pNode, TargetPos)) {
		for (int i = 0; i < MAXSIZE; i++) {
			if (pNode->m_Child[i] == nullptr) {
				return pNode;
			}
			// 자식 비교
			if (this->isRact(pNode->m_Child[i], TargetPos)) {
				return FindNode(pNode->m_Child[i], TargetPos);
			}
		}

		/*else if (this->isRact(m_pRootNode->m_Child[1], TargetPos)) {
			return FindNode(pNode->m_Child[1], TargetPos);
		}
		else if (this->isRact(m_pRootNode->m_Child[2], TargetPos)) {
			return FindNode(pNode->m_Child[2], TargetPos);
		}
		else if (this->isRact(m_pRootNode->m_Child[3], TargetPos)) {
			return FindNode(pNode->m_Child[3], TargetPos);
		}*/
	}
}

void JQuadTree::AddObject(JVector2 pos){
	JNode* targetNode = FindNode(m_pRootNode,pos);

	targetNode->m_ObjectList.push_back(pos);

}

void JQuadTree::AddObject(JObject *player) {
	JNode* targetNode = FindNode(m_pRootNode, player->m_Pos);
	this->m_Dynamic_ObjectAllList.insert(std::make_pair(player->m_sName, player));
	player->iIndexNode = targetNode->m_iIndex;
	targetNode->m_Dynamic_ObjectList.insert(std::make_pair(player->m_sName, player));
}

JNode* JQuadTree::FindIndexNode(int &iIndex) {
	JNode* target;

	return this->FindIndexQueue(this->m_pRootNode, iIndex);

}

JNode* JQuadTree::FindIndexQueue(JNode* pNode, int& iIndex) {
	JNode* retNode = nullptr;
	JNode* retQNode = nullptr;

	for (int i = 0; i < MAXSIZE; i++)
	{
		this->m_Queue.push(pNode->m_Child[i]);
	}

	retQNode = this->m_Queue.front();
	this->m_Queue.pop();
	if (retQNode->m_iIndex == iIndex) {
		return retQNode;
	}
	retNode = FindIndexQueue(retQNode, iIndex);

	if (retNode == nullptr)
	{
		return nullptr;
	}

}

JNode* JQuadTree::Preorder(JNode* pNode, int& iIndex)
{
	JNode* ret = nullptr;
	if (pNode == nullptr)
		return nullptr;
	if (pNode->m_iIndex == iIndex) {
		return pNode;
	}
	for (int iNode = 0; iNode < MAXSIZE; iNode++) {
		if (pNode->m_Child[iNode]->m_iIndex == iIndex) {
			return pNode->m_Child[iNode];
		}
		ret = Preorder(pNode->m_Child[iNode], iIndex);
		if (ret != nullptr) {
			return ret;
		}
	}
}


// 
void JQuadTree::Frame(JObject* player, float fTime)
{
	//pFind->m_Dynamic_ObjectList.erase(player->m_sName);
	JNode* delObjectNode = FindIndexNode(player->iIndexNode);
	this->m_Queue = std::queue<JNode*>();
	
	player->m_Velocity = player->m_fAcceleration * fTime;
	player->m_Velocity.x = 10.0f;
	player->m_Velocity.y = 10.0f;
	player->m_Pos += player->m_Velocity * fTime;

	// 최대 크기를 넘어갔을 경우 최대값으로 설정한다.
	if (player->m_Pos.x > this->m_pRootNode->m_Rect.wh.x) {
		player->m_Pos.x = this->m_pRootNode->m_Rect.wh.x;
	}
	if (player->m_Pos.y > this->m_pRootNode->m_Rect.wh.y) {
		player->m_Pos.y = this->m_pRootNode->m_Rect.wh.y;
	}
	//플레이어의 현 위치의 노드 주소를 얻는다.
	JNode* pFind = FindPlayerNode(m_pRootNode, player->m_Pos, player->m_sName);

	//플레이어를 추가한다.
	this->AddObject(player);
	//전 위치에 플레이어 데이터를 지운다.
	delObjectNode->m_Dynamic_ObjectList.erase(player->m_sName);
	if (pFind != nullptr)
	{
		cout << pFind->m_iIndex << " ";
	}
}

bool JQuadTree::isRact(JNode* pNode, JVector2 pos) {
	if (pNode->m_Rect.p0.x <= pos.x &&
		pNode->m_Rect.p0.y <= pos.y &&
		pNode->m_Rect.p1.x >= pos.x &&
		pNode->m_Rect.p1.y >= pos.y)
	{
		return true;
	}
	return false;
}