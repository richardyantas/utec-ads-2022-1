// https://stackoverflow.com/questions/19732319/difference-between-size-t-and-unsigned-int

#include <vector>
#include <list>

using namespace std;
const int maxColision = 3;
const float maxFillFactor = 0.5;

template<typename TK, typename TV>
class ChainHash
{
private:    
  struct Entry{
		TK key;		
		TV value;
		size_t hashcode;
		Entry(TK _key, TV _value, size_t _hashcode){
        key = _key;
        value = _value;
				hashcode = _hashcode;
    }
	};
	list<Entry> *arr;
	int capacity;//tamanio del arr
  int size;//cantidad de elementos totales

public:
    ChainHash(){
		// TODO: asignar un tamanio inicial al arr
		capacity = 10;
		arr = new list<Entry>[capacity];
		size = 0;
	}

	void set(TK key, TV value){
		if(fillFactor() >= maxFillFactor) rehashing();
		size_t hashcode = getHashCode(key);
		int index = hashcode % capacity;
		//TODO: insertar el Entry(key, value) en index, manejando colisiones
		for(auto it=arr[index].begin(); it!=arr[index].end();it++){
			if(it->key==key){
				it->value=value;
				return;
			}
		}
		arr[index].push_back(Entry(key, value, hashcode));
		size++;
	}

	TV get(TK key){
		int index = getHashCode(key)%capacity;
		// list<Entry>::iterator  // before
		typename list<Entry>::iterator it=arr[index].begin();  // add typename or use just "auto" for C++11  
		for(; it!=arr[index].end(); ++it){
			if(it->key  == key ){
				return it->value;
			}
		}		
		cout << "key is not in the hash table" << endl;		
	}
			
	void remove(TK key){
		int index = getHashCode(key) % capacity;	
		for(auto it=arr[index].begin(); it!=arr[index].end();it++){
			if(it->key==key){
				arr[index].clear();
				return;
			}
		}
		// TV value;
		// int Pos_Delete;
		// size_t hashcode = getHashCode(key);
		// int index = hashcode % capacity;
		// Entry index_it = arr[index].begin();
		// for (int i; i < arr[index].size(); i++){
		// 	if(key == index_it.key)
		// 		Pos_Delete = i;
		// 	else
		// 		advance(index_it,1);
		// }
		// arr[index].erase(Pos_Delete);
	}

	auto begin(int index){
		return arr[index].begin();
	}

	auto end(int index){
		return arr[index].end();
	}

	unsigned int bucket_count(){
		return capacity;	// size
	}

	unsigned int bucket_size(int i){
		return arr[i].size();
  }

	//TODO: implementar el operador corchete [ ]

private:
	double fillFactor(){
		return size / (capacity * maxColision);
	}

	size_t getHashCode(TK key){
		std::hash<TK> ptr_hash;
		return ptr_hash(key);
	}

	void rehashing(){		
		int last_capacity = capacity;
		capacity = capacity*2;
		list<Entry> *new_arr = new list<Entry>[capacity];
		for (unsigned i = 0; i < last_capacity; ++i)
		{		
			for (auto it = arr[i].begin(); it != arr[i].end(); ++it){
				int new_index = it->hashcode % capacity;
				new_arr[new_index].push_front(Entry(it->key, it->value, it->hashcode));
			}		
		}  
		delete arr;
		arr = new_arr;
	};

};
