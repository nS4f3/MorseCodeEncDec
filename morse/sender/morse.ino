
#define Out 8
#define CLOCK_PULSE 2
#define dot 20 //microsec if micro 1 else ms
#define micro 0


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

struct Letter{
    short value; // for shorts 1 for longs 2 (_:2,.:1)
    struct Letter* next;
};

struct Word{
    struct Word* next;
    struct Letter* letter_head;
};

struct Sequence{
    struct Sequence* next;
    struct Word* head;
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

int isEmpty(struct Sequence* sequence){
    if(sequence->head == NULL) return 1;
    else return 0;
}

struct Sequence* enqueue(struct Sequence* sequence,struct Word* word_head){
    if(isEmpty(sequence)){
        sequence->head = word_head;
    }
    else{
        struct Sequence* pointer = sequence;
        while(pointer->next != NULL){
            pointer = pointer->next;
        }

        struct Sequence* seq = (struct Sequence*) malloc(sizeof(struct Sequence));
        seq->next = NULL;
        seq->head = word_head;
        pointer->next = seq;
    }

    return sequence;
}


struct Letter* enqueueLetter(struct Letter* head,struct Letter* let){
    struct Letter* pointer = head;
    while(pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next = let;
    return head;
}


struct Letter* getLetter(char letter){

    // size of an array is sizeof(arr)/sizeof(arr[0])
    struct Array* array = getArray(letter);



    //printf("%d\n\n",*(array->arr+1));
    //printf("%d\n\n",*(a+1));
   //

    struct Letter* head = malloc(sizeof(struct Letter));
    head->next = NULL;
    //printf("%d",&arr[0]);
    head->value = *(array->arr);
    for(int i = 1; i < array->size;i++){
        struct Letter* let = malloc(sizeof(struct Letter));
        let->next = NULL;
        let->value = *(array->arr+i);
        head = enqueueLetter(head,let);
    }
    free(array);
    return head;

}

struct Word* enqueueWord(struct Word* head,struct Word* word){
    struct Word* pointer = head;
    while(pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next = word;
    return head;
}


struct Word* createWord(char *words){// maximum amount of letter that a word can have 20 we need to change this


    struct Word* head = malloc(sizeof(struct Word));
    head->next = NULL;
    head->letter_head = getLetter(words[0]);
    for(int i = 1; i < 20;i++){
        if(words[i] == '\000'){
            break;
        }
        struct Word* word = malloc(sizeof(struct Word));
        word->next = NULL;
        word->letter_head = getLetter(words[i]);
        head = enqueueWord(head,word);

    }

    return head;

}


struct Sequence* createSequence(char message[27]){
    struct Sequence* head = (struct Sequence*) malloc(sizeof(struct Sequence));
    head->next = NULL;
    head->head = NULL;

    int point = -1;

    char* word;
    for(int i = 0 ; i < 27;i++){
        if(message[i] == '\000'){

            word = (char*) calloc((i-point)*sizeof( char),1);
            for(int x= point+1;x <i;x++){
                word[x-(point+1)] = message[x];

            }
            head = enqueue(head, createWord(word));
            free(word);
            break;
        }
        if(message[i] == 0x20){
            word = (char*) calloc((i-point)*sizeof(char ),1);
            for(int x= point+1;x <i;x++){
                word[x-(point+1)] = message[x];

            }

            head = enqueue(head, createWord(word));
            point = i;
            free(word);

        }

    }

    return head;

}
int isEqual(struct Letter* letter1, struct Letter* letter2){
    struct Letter* pointer1 = letter1;
    struct Letter* pointer2 = letter2;

    while (pointer1 != NULL || pointer2 != NULL){
        if(pointer1->value != pointer2->value) break;
        else{
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }
    }
}

/*
struct TrieNode* printTrie(struct TrieNode* node,short val){
    if(val==1){
        return node->left;
    }
    else{
        return node->right;
    }
}
*/

void printLetter(struct Letter* letter_head,struct TrieNode* root){
    struct Letter* pointer = letter_head;
    //struct TrieNode* temp = root;
    while (pointer != NULL){
        //set high the outpin
        //delay the value of pointer
        //set low the outpin
        //printf("%s",pointer->value == 1 ? "." : "_");
        Serial.print(pointer->value == 1 ? "." : "_");
        if(pointer->value == 1){
          /*
          */

          
          
         if(micro == 1){
          digitalWrite(Out,HIGH);
          delayMicroseconds(dot/2);
          digitalWrite(CLOCK_PULSE,HIGH);
          delayMicroseconds(dot/2);
          digitalWrite(CLOCK_PULSE,LOW);
          digitalWrite(Out,LOW);
         }
         else{
          digitalWrite(Out,HIGH);
          delay(dot/2);
          digitalWrite(CLOCK_PULSE,HIGH);
          delay(dot/2);
          digitalWrite(CLOCK_PULSE,LOW);
          digitalWrite(Out,LOW);
         }
        }
        else{
          //tre always 2 time of dot
          /*
          */

          
          if(micro==1){
            digitalWrite(Out,HIGH);
          delayMicroseconds(dot/2);
          digitalWrite(CLOCK_PULSE,HIGH);
          delayMicroseconds(dot/2);
          digitalWrite(CLOCK_PULSE,LOW);
          delayMicroseconds(dot/2);
          digitalWrite(CLOCK_PULSE,HIGH);
          delayMicroseconds(dot/2);
          digitalWrite(CLOCK_PULSE,LOW);
          digitalWrite(Out,LOW);
          }

          else{
            digitalWrite(Out,HIGH);
          delay(dot/2);
          digitalWrite(CLOCK_PULSE,HIGH);
          delay(dot/2);
          digitalWrite(CLOCK_PULSE,LOW);
          delay(dot/2);
          digitalWrite(CLOCK_PULSE,HIGH);
          delay(dot/2);
          digitalWrite(CLOCK_PULSE,LOW);
          digitalWrite(Out,LOW);
          }
           
        }
        //temp= printTrie(temp,pointer->value);
        pointer = pointer->next;
        //delay(letterRest);
        /*
        */

        
        if(micro==1){
          delayMicroseconds(dot/2);
        digitalWrite(CLOCK_PULSE,HIGH);
        delayMicroseconds(dot/2);
        digitalWrite(CLOCK_PULSE,LOW);
        }

        else{
          delay(dot/2);
        digitalWrite(CLOCK_PULSE,HIGH);
        delay(dot/2);
        digitalWrite(CLOCK_PULSE,LOW);
        }
         
       
        
    }
    //printf("%c",temp->val);
}

void printWord(struct  Word* word_head,struct TrieNode* root){
    struct Word* pointer = word_head;
    while (pointer != NULL){
        printLetter(pointer->letter_head,root);
        //printf(" ");
        Serial.print(" ");
        
        //delay of 1 sec
        pointer = pointer->next;
        //delay(wordRest-letterRest);
        /*
        */

        if(micro==1){
          
        delayMicroseconds(dot/2);
        digitalWrite(CLOCK_PULSE,HIGH);
        delayMicroseconds(dot/2);
        digitalWrite(CLOCK_PULSE,LOW);
        
          }

          else{
            delay(dot/2);
        digitalWrite(CLOCK_PULSE,HIGH);
        delay(dot/2);
        digitalWrite(CLOCK_PULSE,LOW);
          }
 
 
    }
}



void printSequence(struct Sequence* sequence_head,struct TrieNode* root){
    struct Sequence* pointer = sequence_head;
    while (pointer != NULL){
        printWord(pointer->head,root);
        
        Serial.print(" ");
        //printf("  ");
        //delay of 2 sec

        pointer = pointer->next;
        //delay(wordRest+letterRest);
        /*
        */

        
        if(micro==1){
          delayMicroseconds(dot/2);
        digitalWrite(CLOCK_PULSE,HIGH);
        delayMicroseconds(dot/2);
        digitalWrite(CLOCK_PULSE,LOW);
        }

        else{
          delay(dot/2);
        digitalWrite(CLOCK_PULSE,HIGH);
        delay(dot/2);
        digitalWrite(CLOCK_PULSE,LOW);
        }
         
   
        
        
    }
}

//struct TrieNode* pointer; //for receiver
struct TrieNode* TrieRoot;
struct Sequence* sequence;
int repeat = 0;



void setup() {
  // put your setup code here, to run once:
  char c[27]= "selamlar millet";
  sequence = createSequence(c);
  //TrieRoot = initTrie(); //for receiver
  //pointer = TrieRoot;
  pinMode(Out,OUTPUT);
  pinMode(CLOCK_PULSE,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("");
  delay(1000);
  for(;repeat < 1;repeat++){
    printSequence(sequence,TrieRoot);
    digitalWrite(CLOCK_PULSE,HIGH);
    digitalWrite(CLOCK_PULSE,LOW);
  }
  

}
