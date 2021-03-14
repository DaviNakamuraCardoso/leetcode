"""

"""

def main():
    for row in solution([[0, 0, -1, 0], [0, 0, 0, 0], [-1, 0, -2, 0], [0, 0, -1, -1]]):
        print(row)


def solution(matrix):
    gates = find_gates(matrix)
    return get_matrix(matrix, gates)


def find_gates(matrix):
    gates = []
    for i in range(0, len(matrix)):
        for j in range(0, len(matrix[i])):
            if not is_safe(matrix, i, j):
                continue
            if matrix[i][j] == -2:
                gates.append([i, j])

    return gates


def is_safe(matrix, i, j):
    if i >= len(matrix) or i < 0 or j >= len(matrix[i]) or j < 0:
        return False

    return (matrix[i][j] != -1)


def get_matrix(matrix, gates):

    for i in range(0, len(matrix)):
        for j in range(0, len(matrix[i])):
            if not is_safe(matrix, i, j):
                continue
            if matrix[i][j] != -2:
                matrix[i][j] = min_dist(i, j, gates)

    return matrix


def min_dist(i, j, gates):
    distances = sorted(gates, key= lambda gate: abs(gate[0]-i) + abs(gate[1]-j))
    return abs(distances[0][0]-i) + abs(distances[0][1]-j)


main()
