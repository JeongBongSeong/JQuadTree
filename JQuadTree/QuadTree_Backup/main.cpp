#include"JQuadTree.h"

int main(){
	JQuadTree* JTree = new JQuadTree();
	JObject*player = new JObject();
	player->Init("JBS", 54.0f, 35.0f,10.0f,10.0f, 1.0f);
	JTree->Init(100, 100);
	JTree->AddObject(player);

	float fSec = 0.0f;

	while(fSec < 20) {
		JTree->Frame(JTree->m_Dynamic_ObjectAllList.find("JBS")->second,(10.0f / 1000.0f));
		Sleep(10);
		fSec += 10.0f / 1000.0f;
	}
	srand(time(NULL));

	cout << "\nhello" << endl;
	return 0;




	for (int i = 0; i < 10; i++) {
		JVector2 pos;
		pos.x = (float)(rand() % 100);
		pos.y = (float)(rand() % 100);

		cout << pos.x << " " << pos.y << endl;
		JTree->AddObject(pos);
	}




	
	


	std::cout << "Hello World!\n";
}
