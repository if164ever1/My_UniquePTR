#pragma once



template <typename Container>
class Node
{
public:
    template <typename Iterator>

    /// <summary>
    /// Implement class iterator throut our container
    /// </summary>
    /// <typeparam name="Iterator"></typeparam>
    class NodeIterator
    {
    private:
        friend class Node;
    public:
        typedef Iterator iterator_type;
        //typedef std::input_iterator_tag m_iterator_category;
        //typedef iterator_type value_type;
        //typedef ptrdiff_t different_type;
        typedef iterator_type& reference;
        //typedef iterator_type* pointer;
        iterator_type* pvalue;
    private:
        NodeIterator(Iterator* p)
            : pvalue(p)
        {}

    public:
        NodeIterator(const NodeIterator& it) : pvalue(it->pvalue) {}
        bool operator != (NodeIterator const& other) const {
            return pvalue != other.pvalue;
        }

        bool operator == (NodeIterator const& other) const {
            return pvalue == other.pvalue;
        }

        typename NodeIterator::reference operator*() const {
            return *pvalue;
        }

        NodeIterator& operator++() {
            if (pvalue->pparent == nullptr)
                pvalue = nullptr;
            else if (pvalue->pparent->pright.get() == pvalue)
                pvalue = pvalue->pparent;

            else {
                pvalue = pvalue->pparent;
                if (pvalue->pright.get() != nullptr)
                {
                    pvalue = pvalue->pright.get();
                    while (pvalue->pleft.get() != nullptr)
                        pvalue = pvalue->pleft.get();
                }
            }
            return *this;
        }
    };


/// <summary>
/// Its our container
/// </summary>
/// <typeparam name="Container"></typeparam>
public:
    Node* pparent;
    Container m_value;
    std::unique_ptr<Node> pleft;
    std::unique_ptr<Node> pright;

    typedef NodeIterator<Node> iterator;
    typedef NodeIterator<const Node> const_iterator;

    Node(const Container& value, std::unique_ptr<Node> left, std::unique_ptr<Node> right, Node* parent)
        : m_value(value), pleft(std::move(left)), pright(std::move(right)), pparent(parent)
    {}
    Node(const Node&) = delete;
    Container& GetValue() { return m_value; }
    std::unique_ptr<Node>& GetLeft() { return pleft; }
    std::unique_ptr<Node>& GetRight() { return pright; }

    iterator begin_() {
        Node* node = this;
        while (node->pleft != nullptr)
            node = node->pleft.get();
        return iterator(node);
    }

    iterator end_() { return nullptr; }

    const_iterator begin() const {
        const Node* node = this;
        while (node->pleft != nullptr)
            node = node->pleft.get();
        return const_iterator(node);
    }
    const_iterator end() const { return nullptr; }

    friend std::ostream& operator << (std::ostream& os, const Node& n) {
        return os << n.m_value;
    }

private:


};
