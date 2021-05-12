// Users_Iterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HeaderUsersIterator.h"
#include "HUserUniqueptr.h"

/*
                                     one - root
                                    /       \
                              two - left    tgree - right
                               /     \         /        \
                            four     fifth    six        seven
*/

/// <summary>
/// This foonction show us how to wirk with standart UNIQUE_PTR
/// </summary>
void fooTest1()
{
    auto root = std::make_unique<Node<std::string>>("one", nullptr, nullptr, nullptr);
    root->GetLeft() = std::make_unique<Node<std::string>>("two", nullptr, nullptr, root.get());

    auto it = root->begin();

    std::cout << *it;
    ++it;
    std::cout << *it;
}

/// <summary>
/// Test its work with users PTR
/// </summary>
void test()
{
    Node<std::string> *s = new Node<std::string>("one", nullptr, nullptr, nullptr);

    auto q = CUniqueptr<Node<std::string>>(s);
    (q.Getptr())->pleft = ("two", nullptr, nullptr, q.Getptr());




  /* Node<std::string> *root = new Node<std::string>("one", nullptr, nullptr, nullptr);
   auto myPtr = CUniqueptr<Node<std::string>>(root);
   std::cout << (myPtr.Getptr())->m_value;*/
}




/// <summary>
/// This foonction show us how to wirk with standart UNIQUE_PTR
/// </summary>
void fooTest2()
{
    auto root = std::make_unique<Node<std::string>>("one", nullptr, nullptr, nullptr);
    root->GetLeft() = std::make_unique<Node<std::string>>("two", nullptr, nullptr, root.get());
    root->pright = std::make_unique<Node<std::string>>("three", nullptr, nullptr, root.get());

    auto root2 = root->pleft.get();
    auto root3 = root->pright.get();

    root2->pleft = std::make_unique<Node<std::string>>("four", nullptr, nullptr, root2);
    root2->pright = std::make_unique<Node<std::string>>("fifth", nullptr, nullptr, root2);

    root3->pleft = std::make_unique<Node<std::string>>("six", nullptr, nullptr, root3);
    root3->pright = std::make_unique<Node<std::string>>("seven", nullptr, nullptr, root3);


    for (auto it = root->begin(); it != root->end(); ++it)
    {
        std::cout << *it << "\n";
    }
}


int main()
{
    test();


}

