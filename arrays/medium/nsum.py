def n_sum(n, target, arr):
    if n == 1:
        if target in arr:
            return [[target]]

    s = []

    for i in range(len(arr)):
        if arr[i] == arr[i-1] and i > 0:
            continue

        matches = n_sum(n-1, target-arr[i], arr[i+1:])
        for match in matches:
            s.append([arr[i]] + match)

    return s


def main():
    s = n_sum(5, 0, sorted([-1, 0, 1, 2, -1, -4, 1, 1, 3]))
    print(s)
main()
