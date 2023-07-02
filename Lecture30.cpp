// Q1 Min Heap
class Minheap{
    int capacity;
    int size;
    int *heap;

    int parent(int index){
        return (index-1)/2;
    }
    int leftChild(int index)    return (2*index+1);
    int rightChild(int index)   return (2*index+2);
    void minHeapify(int index){
        int smallest = index;
        int l = leftChild(index);
        int r = rightChild(index);
        if(l<this->size && this->heap[smallest]> this->heap[l])    smallest=l;
        if(r<this->size && this->heap[smallest]> this->heap[r])    smallest=r;
        if(smallest!=index){
            swap(this->heap[index],this->heap[smallest]);
            minHeapify(smallest);
        }    
    }
    public:
    Minheap(int capacity){
        this->capacity=capacity;
        this->size=size;
        this->heap=new int[this->capacity];
    }
    void Push(int key){
        if(this->size==this->capacity){
            return;
        }
        this->size++;
        int index=this->size-1;
        this->heap[index]=key;

        while(index!=0 && this->heap[index]<this->heap[parent(index)]){
            swap(this->heap[index],this->heap[parent(index)]);
            index=parent(index);
        }
    }
    int top(){
        return this->size==0? 0:this->heap[0];
        // or
        // if(this->size==0)   return -1;
        // return this->heap[0];
    }
    void Pop(){
        swap(this->size == 0)   return;
        if(this->size == 1){
            this->size--;
            return;
        }
        this->heap[0]=this->heap[this->size-1];
        this->size--;
        minHeapify(0);
    }
}


//Median 
vector<double> medianOfRunningStream(vector<double> &vec){
    int N=vec.size();
    vector<double> medians(N);
    priority_queue<double> maxHeap;
    priority_queue<double,vector<double>,greater<double>> minHeap;
    maxHeap.push(vec[0]);
    medians[0]=vec[0];
    for(int i=0;i<N;i++){
        maxHeap.push(vec[i]);
        while(maxHeap.size()-minHeap.size()>1){
            double top=maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        if(i&1) medians[i]=maxHeap.top();
        else     medians[i]=(maxHeap.top()+minHeap.top())/2;
    }
    return medians;

int main(){
    
}