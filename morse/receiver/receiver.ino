#define CLOCK_PULSE 2
#define IN 8



short a[2] = {1,2};
short b[4] = {2,1,1,1};
short c[4] = {2,1,2,1};
short d[3] = {2,1,1};
short e[1] = {1};
short f[4] = {1,1,2,1};
short g[3] = {2,2,1};
short h[4] = {1,1,1,1};
short i[2] = {1,1};
short j[4] = {1,2,2,2};
short k[3] = {2,1,2};
short l[4] = {1,2,1,1};
short m[2] = {2,2};
short n[2] = {2,1};
short o[3] = {2,2,2};
short p[4] = {1,2,2,1};
short r[3] = {1,2,1};
short s[3] = {1,1,1};
short t[1] = {2};
short u[3] = {1,1,2};
short v[4] = {1,1,1,2};
short y[4] = {2,1,2,2};
short z[4] = {2,2,1,1};

struct Array{
    short *arr;
    short size;
    char val;
};

struct TrieNode{
    char val;
    struct TrieNode* left;
    struct TrieNode* right;

};

struct Array* getArray(char letter){
    struct Array* array = (struct Array*)malloc(sizeof(struct Array));
    array->arr = NULL;
    array->size = 0;
    array->val = NULL;
    switch (letter) {
        case 'a':
            array->arr = a;
            array->size = sizeof(a)/sizeof(short );
            array->val = 'a';
            break;
        case 'b':
            array->arr = b;
            array->size = sizeof(b)/sizeof(short );
            array->val = 'b';
            break;
        case 'c':
            array->arr = c;
            array->size = sizeof(c)/sizeof(short );
            array->val = 'c';
            break;
        case 'd':
            array->arr = d;
            array->size = sizeof(d)/sizeof(short );
            array->val = 'd';
            break;
        case 'e':
            array->arr = e;
            array->size = sizeof(e)/sizeof(short );
            array->val = 'e';

            break;
        case 'f':
            array->arr = f;
            array->size = sizeof(f)/sizeof(short );
            array->val = 'f';

            break;
        case 'g':
            array->arr = g;
            array->size = sizeof(g)/sizeof(short );
            array->val = 'g';

            break;
        case 'h':
            array->arr = h;
            array->size = sizeof(h)/sizeof(short );
            array->val = 'h';

            break;
        case 'i':
            array->arr = i;
            array->size = sizeof(i)/sizeof(short );
            array->val = 'i';

            break;
        case 'j':
            array->arr = j;
            array->size = sizeof(j)/sizeof(short );
            array->val = 'j';

            break;
        case 'k':
            array->arr = k;
            array->size = sizeof(k)/sizeof(short );
            array->val = 'k';

            break;
        case 'l':
            array->arr = l;
            array->size = sizeof(l)/sizeof(short );
            array->val = 'l';

            break;
        case 'm':
            array->arr = m;
            array->size = sizeof(m)/sizeof(short );
            array->val = 'm';

            break;
        case 'n':
            array->arr = n;
            array->size = sizeof(n)/sizeof(short );
            array->val = 'n';

            break;
        case 'o':
            array->arr = o;
            array->size = sizeof(o)/sizeof(short );
            array->val = 'o';

            break;
        case 'p':
            array->arr = p;
            array->size = sizeof(p)/sizeof(short );

            array->val = 'p';

            break;
        case 'r':
            array->arr = r;
            array->size = sizeof(r)/sizeof(short );
            array->val = 'r';

            break;
        case 's':
            array->arr = s;
            array->size = sizeof(s)/sizeof(short );
            array->val = 's';

            break;
        case 't':
            array->arr = t;
            array->size = sizeof(t)/sizeof(short );

            array->val = 't';

            break;
        case 'u':
            array->arr = u;
            array->size = sizeof(u)/sizeof(short );
            array->val = 'u';

            break;
        case 'v':
            array->arr = v;
            array->size = sizeof(v)/sizeof(short );
            array->val = 'v';

            break;
        case 'y':
            array->arr = y;
            array->size = sizeof(y)/sizeof(short );
            array->val = 'y';

            break;
        case 'z':
            array->arr = z;
            array->size = sizeof(z)/sizeof(short );
            array->val = 'z';

            break;

    }
    return array;

}

struct TrieNode* insertTrie(struct TrieNode** root,struct Array* array){
    struct TrieNode* pointer = *root;
    for(int i = 0; i < array->size;i++){
        if(*(array->arr+i) == 1){
            //left
            if(pointer->left == NULL){
                struct TrieNode* tmp = (struct TrieNode*) malloc(sizeof(struct TrieNode));
                tmp->left = NULL;
                tmp->right =NULL;
                tmp->val =NULL;
                pointer->left = tmp;
            }
            pointer = pointer->left;
        }
        else{
            if(pointer->right == NULL){
                struct TrieNode* tmp = (struct TrieNode*) malloc(sizeof(struct TrieNode));
                tmp->left = NULL;
                tmp->right =NULL;
                tmp->val =NULL;
                pointer->right = tmp;
            }
            pointer = pointer->right;
        }

    }
    pointer->val = array->val;
    return *root;


}

struct TrieNode* initTrie(){

    char alpha[24] = "abcdefghijklmnoprstuvyz";
    struct TrieNode* root = (struct TrieNode*) malloc(sizeof(struct TrieNode));
    root->val = NULL;
    root->left=NULL;
    root->right=NULL;
    for(int i = 0; i <24;i++){
        struct Array* array = getArray(alpha[i]);
        root = insertTrie(&root,array);
        free(array);
    }
    return root;


}


struct TrieNode* printTrie(struct TrieNode* node,short val){
    if(val==1){
        return node->left;
    }
    else{// 2
        return node->right;
    }
}


struct TrieNode* pointer; //for receiver
struct TrieNode* TrieRoot;

enum State{
  Zero,
  Dot,
  Tre,
  Space,
  BetweenZeroAndSpace
};

State state;

unsigned long currentTime;


void setup() {
  // put your setup code here, to run once:
  //TrieRoot = initTrie(); //for receiver
  //pointer = TrieRoot;
  pinMode(IN,INPUT);
  pinMode(CLOCK_PULSE,INPUT);
  state = Zero;
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(CLOCK_PULSE),onClockPulse,RISING);
  TrieRoot = initTrie();
  pointer = TrieRoot;
  currentTime = 0;
  
}


void onClockPulse(){
  int val = digitalRead(IN);
  

  currentTime = millis();

  
  switch(state){
    case Zero:
      if(val == 1){
        state = Dot;
      }
      else{
        state = BetweenZeroAndSpace;
      }
      
    break;

    case Dot:
      if(val==1){
        state = Tre;
      }
      else{
        
        pointer= printTrie(pointer,1);
        state = Zero;
      }
    break;

    case Tre:
      pointer= printTrie(pointer,2);
      state = Zero;
    break;


    case Space:
      if(val == 1){
        Serial.print(pointer->val);
        Serial.print(" ");
        pointer = TrieRoot;
        state = Dot;
      }
      else{
        Serial.print(pointer->val);
        Serial.println();
        pointer = TrieRoot;
        state = Zero;
      }
    break;

    case BetweenZeroAndSpace:
      if(val == 1){
        Serial.print(pointer->val);
        pointer = TrieRoot;
        state = Dot;
      }
      else{
        state = Space;
      }
    break;
  }
  
}





void loop(){
  

   
}
