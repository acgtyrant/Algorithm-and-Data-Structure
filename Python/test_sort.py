#!/usr/bin/env python2
# -*- coding: UTF-8 -*-


import unittest
import random
from sort import insertion_sort as method


class TestStringMethods(unittest.TestCase):

    def test_empty_sequence(self):
        self.assertEqual(method([]), [])

    def test_one_sequence(self):
        self.assertEqual(method([1]), [1])

    def test_increment_sequence(self):
        self.assertEqual(
                method(list(range(10))),
                list(range(10)))

    def test_decrease_sequence(self):
        self.assertEqual(
                method(list(range(10, 0, -1))),
                list(range(1, 11)))

    def test_random_sequence(self):
        sequence = list(range(10))
        random.shuffle(sequence)
        self.assertEqual(method(sequence), list(range(10)))


if __name__ == '__main__':
    unittest.main()
