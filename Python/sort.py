def selection_sort(sequence):
    for index, element in enumerate(sequence):
        min_element = min(sequence[index:])
        min_index = sequence.index(min_element)
        sequence[index], sequence[min_index] = min_element, element
    return sequence


def insertion_sort(sequence):
    new_sequence = []
    for index, element in enumerate(sequence):
        higger_index = 0
        while higger_index < len(new_sequence) and \
                new_sequence[higger_index] <= element:
            higger_index += 1
        new_sequence.insert(higger_index, element)
    return new_sequence
