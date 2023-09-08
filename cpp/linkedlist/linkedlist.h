#pragma once

#include <iostream>
#include <memory>

#define print(x) std::cout << x << std::endl;

template <typename T>
class LinkedList {
private:
    struct Node {
        T m_data;
        std::unique_ptr<Node> nextNode;
        Node(const T &value) : m_data(std::move(value)), nextNode(nullptr) {}
    };

    std::unique_ptr<Node> headNode;

public:
    ~LinkedList(){
        print("Linkelist out of scope");
    }
    LinkedList() : headNode(nullptr) {
        print("Linkedlist created");
    }

    void insertFront(const T &value) {
        auto newNode( std::make_unique<Node>(std::move(value)));
        newNode->nextNode = std::move(headNode);
        headNode = std::move(newNode);
    }

    void insertBack(const T &value) {
        auto newNode( std::make_unique<Node>(std::move(value)));
        if (headNode == nullptr) {
            headNode = std::move(newNode);
        } else {
            Node* currentNode = headNode.get();
            while (currentNode->nextNode != nullptr) {
                currentNode = currentNode->nextNode.get();
            }
            currentNode->nextNode = std::move(newNode);
        }
    }

    bool remove(const T &value) {
        if (headNode == nullptr) {
            return false;
        }

        if (headNode->m_data == value) {
            headNode = std::move(headNode->nextNode);
            return true;
        }

        Node* currentNode = headNode.get();
        while (currentNode->nextNode != nullptr && currentNode->nextNode->m_data != value) {
            currentNode = currentNode->nextNode.get();
        }

        if (currentNode->nextNode == nullptr) {
            return false;
        }

        currentNode->nextNode = std::move(currentNode->nextNode->nextNode);
        return true;
    }

    bool search(const T &value) const {
        Node* currentNode = headNode.get();
        while (currentNode != nullptr) {
            if (currentNode->m_data == value) {
                return true;
            }
            currentNode = currentNode->nextNode.get();
        }
        return false;
    }

    void printList() const {
        Node* currentNode = headNode.get();
        while (currentNode != nullptr) {
            std::cout << currentNode->m_data << " ";
            currentNode = currentNode->nextNode.get();
        }
        std::cout << std::endl;
    }
};
