#include <iostream>
#include <vector>
#include <algorithm>

class MagicalContainer
{
private:
    std::vector<int> elements;

public:
    void addElement(int element){}

    void removeElement(int element){}

    size_t size() const
    {return 0;}


const std::vector<int>& getElements() const
{   static const std::vector<int> emptyVector;
    return emptyVector;}

    bool isPrime(int num) const
    {return false;}
};

class AscendingIterator
{
private:
    const MagicalContainer &container;
    std::vector<int> sortedElements;
    size_t index;

public:
    AscendingIterator(const MagicalContainer &cont) : container(cont), sortedElements(container.getElements()), index(0)
    {}

    bool operator==(const AscendingIterator &other) const
    {return false;}

    bool operator!=(const AscendingIterator &other) const
    {return false;}

    bool operator>(const AscendingIterator &other) const
    {return false;}

    bool operator<(const AscendingIterator &other) const
    {return false;}

    int operator*() const
    {return -1;}

    AscendingIterator &operator++()
    {return *this;}

    AscendingIterator begin() const
    {return AscendingIterator(container);}

    AscendingIterator end() const
    {
        AscendingIterator iter(container);
        iter.index = sortedElements.size(); // Point to one position past the last element
        return iter;
    }
};

class SideCrossIterator
{
private:
    const MagicalContainer &container;
    size_t forwardIndex;
    size_t backwardIndex;
    bool forward;

public:
    SideCrossIterator(const MagicalContainer &cont)
        : container(cont), forwardIndex(0), backwardIndex(cont.size() - 1), forward(true) {}

    bool operator==(const SideCrossIterator &other) const
    {return false;}

    bool operator!=(const SideCrossIterator &other) const
    {return false;}

    bool operator>(const SideCrossIterator &other) const
    {return false;}

    bool operator<(const SideCrossIterator &other) const
    {return false;}

    int operator*() const
    {return -1;}

    SideCrossIterator &operator++()
    {return *this;}

    SideCrossIterator begin() const
    {
        SideCrossIterator iter(container);
        iter.forwardIndex = 0;
        iter.backwardIndex = container.size() - 1;
        iter.forward = true;
        return iter;
    }

    SideCrossIterator end() const
    {
        SideCrossIterator iter(container);
        iter.forwardIndex = forward ? container.size() : container.size() - 1;
        iter.backwardIndex = forward ? container.size() - 1 : 0;
        iter.forward = true; // Set to true to indicate the end position
        return iter;
    }
};

class PrimeIterator
{
private:
    const MagicalContainer &container;
    std::vector<int> primeElements;
    size_t index;

public:
    PrimeIterator(const MagicalContainer &cont) : container(cont), index(0){}

    bool operator==(const PrimeIterator &other) const
    {return false;}

    bool operator!=(const PrimeIterator &other) const
    {return false;}

    bool operator>(const PrimeIterator &other) const
    {return false;}

    bool operator<(const PrimeIterator &other) const
    {return false;}

    int operator*() const
    {return -1;}

    PrimeIterator &operator++()
    {return *this;}

    PrimeIterator begin() const
    {return PrimeIterator(container);}

    PrimeIterator end() const
    {return PrimeIterator(container);}

    bool isPrime(int num)
    {return false;}
};
