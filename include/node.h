class node{
public:
	node();
	node(uint8_t* ar, int xx,int yy, int ww, int hh, cinder::Color8u cc);
	node* next;
	node* prev;

	//rectangle
	int x;
	int y;
	int w;
	int h;
	cinder::Color8u c;
};

void insertAfter(node* insert, node* after, node* head);

void remove(node* out);

void move(node* move, int x, int y);
void reverse(node* head);