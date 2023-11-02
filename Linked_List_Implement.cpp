/*
Linked_List_Implement
*/

class LinkedList;

Class ListNode{
private:
  int val;
  ListNode* next;
public:
  ListNode(): val(0), next(NULL){};
  ListNode(int a): val(a),next(NULL){};

  friend class LinkedList;
};

class LinkedList{
private:
  ListNode* first;
public:
  LinkedList():first(0){};

  void push_back();
  void push_front(int x);
  void printList(int x);
  void Delete(int x);
  void clear();
  void reverse();
};

void LinkedList::push_back(int x){
  ListNode* newNode = new ListNode(x);
  if(first == NULL){
      first = newNode;
      return;
  }

  ListNode* cur = first;
  while(cur->next != NULL){
    cur = cur->next;
  }
  cur->next = newNode;
  return;
}

void LinkedList::push_front(int x){
  ListNode* newNode = new ListNode(x);
  newNode->next = first;
  first = newNode;  

  return;
}

void printList(){
  if(first == NULL){
    count << "this list is empty"<<endl;
    return;
  }

  ListNode* cur = first;
  while(cur != NULL){
    cout << cur->val << endl;
    cur = cur->next;
  }
  return;
}

void Delete(int x){
  ListNode* cur = first;
  ListNode* prev = NULL;
  while(cur != NULL && cur->val != x){
    prev = cur;
    cur = cur->next;
  }

  if(cur == first){
    first = cur->next;
    delete cur;
    cur = NULL;
    return;
  }
  else if(cur == NULL){
    cout << "there is no such value in list"<<endl;
    return;
  }
  else {
    prev->next = cur->next;
    delete cur;
    cur = NULL;
    return;
  }
}

void claer(){
  while(first != NULL){
    ListNode* cur = first;
    first = first->next;
    delete cur;
    cur = NULL;
  }
}

void reverse(){
  if(first == NULL || first->next == NULL) return;
  ListNode* prev = NULL;
  ListNode* cur = first;
  ListNode* nxt;
  while(cur != NULL){
    nxt = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nxt;
  }
  return prev;
}



