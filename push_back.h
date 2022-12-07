//
// Created by Nonthachai Plodthong on 5/12/2022 AD.
//

#ifndef MULTIINHERITANCE_PUSH_BACK_H
#define MULTIINHERITANCE_PUSH_BACK_H

#include <iostream>

namespace sdds {
	template<typename T>
	class List {
		struct Node {
			T data{};
			Node *next{}; // store address of next element
			Node *previous{}; // store address of previous element;
		};

		struct iteration {
			// create some aliases for types used internally by algorithms.
			using iterator_category = std::forward_iterator_tag;
			using differnt_type = std::ptrdiff_t;
			using value_type = T;
			using pointer = T *;
			using reference = T &;
			Node *current{};

			bool operator!=(const iteration &it) const { // comparison yes or no BOOL
				return current != it.current;
			}

			bool operator==(const iteration &it) const { // query should mark const prevent any change
				return current == it.current;
			}

			iteration &operator++() {
				if (current != nullptr)
					current = current->next;
				return *this;
			}

			T &operator*() {
				return current->data;
			}
		};

		//size_t m_cnt;
		Node *head{}; // first element of the list
		Node *tail{};



		// last element of the list
	public:
		//TODO add rules of 5
		List() = default;

		List &operator=(const T &object) {
			//self assestment
			if (this != &object) {
				//delete self
				while (head) {
					delete head->data;
					head->next;
					//delete tail->previous->data;
					head++;
				}
				tail->previous = object.tail;
				if (object != nullptr) {
					head = new List();
					while (head) {
						head->next->data = object.head;
						//tail->previous->data = object.tail;
						head++;
					}
				} else {
					head->data = nullptr;
				}
			}
			return *this;
		}

		List &operator=(T &&move) {
			//self assestment
			if (this != &move) {
				while (head) {
					delete head->data;
					head->next;
					head++;
				}
				tail->previous = move.tail;
				if (&move != nullptr) {
					while (head) {
						head->data = move.head;
						head->next;
						head++;
					}
				}
				move->head = nullptr;
				move->tail = nullptr;
			}
			return *this;
		}

		List(T &&movel) {
			*this = std::move(movel);
		}

		List(const T &l) {
			*this = l;
		}


		// add data at the end;
		void push_back(T datas) { // recevied data
			Node *tmp = new Node();
			/*-> (pointer)*/
			tmp->data = datas; // set data taken;
			tmp->next = nullptr; // set next of the list to null
			tmp->previous = tail; // set previous = last element of the list;

			if (head == nullptr) {
				this->head = tmp;  /*list << empty  * add [head =tmp] [tail=tmp]*/
			} else {
				this->tail->next = tmp;
			}
			this->tail = tmp;
		}

		void pop() {
			Node *tmp = new Node();
			tmp->next = nullptr;
			tmp->previous = tail;
			if (head != nullptr) {
				this->head = this->head->next;
			}
		}

		iteration begin() {
			return iteration{head};
		}

		iteration end() {
			if (tail->next != nullptr) {
				return iteration{tail->next};
			}
			return iteration{};
		}

		List &sort() {
			Node *tmp = new Node();

		}

		std::ostream &operator<<(std::ostream &os) {
			os << " | " << head << " | " << '\n';
			head->next;
			os << " | " << tail << " | " << '\n';
			return os;
		}
	};

}
#endif //MULTIINHERITANCE_PUSH_BACK_H
