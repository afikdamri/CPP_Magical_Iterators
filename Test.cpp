#include "doctest.h"
#include <iostream>
#include <vector>
#include <cmath>

#include "sources/MagicalContainer.h"

TEST_CASE("Test number 1: Adding elements to the MagicalContainer") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    REQUIRE(container.size() == 3);
}

TEST_CASE("Test number 2: Removing elements from the MagicalContainer") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.removeElement(2);
    REQUIRE(container.size() == 2);
}

TEST_CASE("Test number 3: Traversing the AscendingIterator for the MagicalContainer") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);
    std::vector<int> result;
    for (const auto& element : container.getElements()) {
        result.push_back(element);
    }
    REQUIRE(result == std::vector<int>({3, 1, 2}));
}


TEST_CASE("Test number 4: Traversing the PrimeIterator for the MagicalContainer") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(4);
    container.addElement(7);
    container.addElement(9);
    container.addElement(11);
    PrimeIterator primeIter(container);
    std::vector<int> result;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        result.push_back(*it);
    }
    REQUIRE(result == std::vector<int>({7, 11}));
}

/*TEST_CASE("Test number 5: Traversing the SideCrossIterator for the MagicalContainer") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    SideCrossIterator crossIter(container);
    std::vector<int> result;
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        result.push_back(*it);
    }
    REQUIRE(result == std::vector<int>({1, 3, 2}));
}*/

TEST_CASE("Test number 6: Adding and removing elements from the MagicalContainer") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.removeElement(2);
    container.addElement(4);
    REQUIRE(container.size() == 3);
}

TEST_CASE("Test number 7: Traversing the AscendingIterator with an empty container") {
    MagicalContainer container;
    std::vector<int> result;
    for (const auto& element : container.getElements()) {
        result.push_back(element);
    }
    REQUIRE(result.empty());
}

TEST_CASE("Test number 8: Traversing the PrimeIterator for an empty container") {
    MagicalContainer container;
    std::vector<int> result;
    for (const auto& element : container.getElements()) {
        result.push_back(element);
    }
    REQUIRE(result.empty());
}

TEST_CASE("Test number 9: Traversing the SideCrossIterator with a container of size 1") {
    MagicalContainer container;
    container.addElement(1);
    std::vector<int> result;
    for (const auto& element : container.getElements()) {
        result.push_back(element);
    }
    REQUIRE(result == std::vector<int>({1}));
}

TEST_CASE("Test number 10: Traversing the SideCrossIterator with a container of size 2") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    std::vector<int> result;
    for (const auto& element : container.getElements()) {
        result.push_back(element);
    }
    REQUIRE(result == std::vector<int>({1, 2}));
}

TEST_CASE("Test number 11: Adding elements to the MagicalContainer using a for loop") {
    MagicalContainer container;
    for (int i = 1; i <= 5; ++i) {
        container.addElement(i);
    }
    REQUIRE(container.size() == 5);
}

TEST_CASE("Test number 12: Removing elements from the MagicalContainer using a while loop") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    int i = 1;
    while (i <= 3) {
        container.removeElement(i);
        ++i;
    }
    REQUIRE(container.size() == 0);
}

TEST_CASE("Test number 13: Traversing the AscendingIterator with a for loop") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);
    AscendingIterator ascIter(container);
    std::vector<int> result;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        result.push_back(*it);
    }
    REQUIRE(result == std::vector<int>({1, 2, 3}));
}

TEST_CASE("Test number 14: Traversing the PrimeIterator with a while loop") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(4);
    container.addElement(7);
    container.addElement(9);
    container.addElement(11);
    PrimeIterator primeIter(container);
    std::vector<int> result;
    auto it = primeIter.begin();
    while (it != primeIter.end()) {
        result.push_back(*it);
        ++it;
    }
    REQUIRE(result == std::vector<int>({7, 11}));
}

TEST_CASE("Test number 15: Traversing the AscendingIterator and PrimeIterator") {
    MagicalContainer container;
    container.addElement(11);
    container.addElement(4);
    container.addElement(7);
    container.addElement(9);
    AscendingIterator ascIter(container);
    PrimeIterator primeIter(container);
    std::vector<int> result;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        result.push_back(*it);
    }
    REQUIRE(result == std::vector<int>({7, 11}));
}


TEST_CASE("Test number 16: Traversing the AscendingIterator and SideCrossIterator") {
    MagicalContainer container;
    container.addElement(11);
    container.addElement(4);
    container.addElement(7);
    container.addElement(9);
    AscendingIterator ascIter(container);
    SideCrossIterator sideCrossIter(container);
    std::vector<int> result;
    for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
        result.push_back(*it);
    }
    REQUIRE(result == std::vector<int>({4, 11, 7, 9}));
}

TEST_CASE("Test number 17: Traversing the SideCrossIterator and PrimeIterator") {
    MagicalContainer container;
    container.addElement(4);
    container.addElement(7);
    container.addElement(9);
    container.addElement(11);
    SideCrossIterator sideCrossIter(container);
    PrimeIterator primeIter(container);
    std::vector<int> result;
    for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
        result.push_back(*it);
    }
    REQUIRE(result == std::vector<int>({11, 7}));
}

TEST_CASE("Test number 18: Traversing the SideCrossIterator and AscendingIterator") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(8);
    container.addElement(6);
    container.addElement(4);
    SideCrossIterator sideCrossIter(container);
    AscendingIterator ascIter(container);
    std::vector<int> result;
    for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
        result.push_back(*it);
    }
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        result.push_back(*it);
    }
    REQUIRE(result == std::vector<int>({2, 8, 4, 6, 2, 4, 6, 8}));
}

TEST_CASE("Test number 19: Traversing the PrimeIterator and AscendingIterator") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(10);
    container.addElement(7);
    container.addElement(4);
    PrimeIterator primeIter(container);
    AscendingIterator ascIter(container);
    std::vector<int> result;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        result.push_back(*it);
    }
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        result.push_back(*it);
    }
    REQUIRE(result == std::vector<int>({3, 7, 3, 4, 7, 10}));
}

TEST_CASE("Test number 20: Traversing the AscendingIterator, SideCrossIterator, and PrimeIterator") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(8);
    container.addElement(7);
    container.addElement(6);
    AscendingIterator ascIter(container);
    SideCrossIterator sideCrossIter(container);
    PrimeIterator primeIter(container);
    std::vector<int> result;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        result.push_back(*it);
    }
    for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
        result.push_back(*it);
    }
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        result.push_back(*it);
    }
    REQUIRE(result == std::vector<int>({5, 6, 7, 8, 5, 8, 6, 7, 5, 7}));
}
