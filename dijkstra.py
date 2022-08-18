def finding_positive(number, matrix_contiguity, checked_points):
    """Ищет положительные значения в матрице смежности
    для передаваемого номера"""
    weights = []
    for i in enumerate(matrix_contiguity[number]):
        if i[1] > 0 and i[0] not in checked_points:
            weights.append(i)
    return weights


def selecting_min(dijkstra_matrix, next_point):
    """Выбирает минимум из списка."""
    min = dijkstra_matrix[next_point[0]] + 999
    for i in enumerate(dijkstra_matrix):
        if i[1] != 0 and i[1] < min:
            min = i[1]
            num = i[0]
    return (num, min)


# Здесь можно ввести свою матрицу смежности
matrix_contiguity = ((0, 7, 9, 0, 0, 14),
                     (7, 0, 10, 15, 0, 0),
                     (9, 10, 0, 11, 0, 2),
                     (0, 15, 11, 0, 6, 0),
                     (0, 0, 0, 6, 0, 9),
                     (14, 0, 2, 0, 9, 0))

point = int(input("Введите начальную точку (подсчет начинать с 0): "))
N = len(matrix_contiguity)
next_point = (point, 0)
string = 'Результат кратчайшего пути по алгоритму Дейкстры от точки ' + \
         str(point) + ' до остальных: '

# Вместо 999 нужно записать любое очень большое число, если длины путей достаточно велики
dijkstra_matrix = [999] * N
dijkstra_matrix[next_point[0]] = 0

result = []
checked_points = [next_point[0]]

for i in range(len(matrix_contiguity) - 1):
    positives = finding_positive(next_point[0], matrix_contiguity,
                                 checked_points)

    for i in range(len(positives)):
        if dijkstra_matrix[positives[i][0]] > positives[i][1] + next_point[1]:
            dijkstra_matrix[positives[i][0]] = positives[i][1] + next_point[1]

    next_point = selecting_min(dijkstra_matrix, next_point)
    dijkstra_matrix[next_point[0]] = 0
    checked_points.append(next_point[0])

    result.append(next_point)

print(string, sorted(result))
