def selection_sort(sequence):
    for index, element in enumerate(sequence):
        min_element = min(sequence[index:])
        min_index = sequence.index(min_element)
        sequence[index], sequence[min_index] = min_element, element
