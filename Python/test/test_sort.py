#!/usr/bin/env python2
# -*- coding: UTF-8 -*-


import unittest
import random
from sort import sort_methods


class TestStringMethods(unittest.TestCase):

    def test_empty_sequence(self):
        for method in sort_methods:
            self.assertEqual(method([]), [])

    def test_one_sequence(self):
        for method in sort_methods:
            self.assertEqual(method([1]), [1])

    def test_increment_sequence(self):
        for method in sort_methods:
            self.assertEqual(method(range(10)), range(10))

    def test_decrease_sequence(self):
        for method in sort_methods:
            self.assertEqual(method(range(10, 0, -1)), range(1, 11))

    def test_random_sequence(self):
        for method in sort_methods:
            self.assertEqual(
                    method(random.shuffle(range(10))),
                    range(10))


if __name__ == '__main__':
    unittest.main()
