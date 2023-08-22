void Backtracking(state) {
    if found_solution(state)
        mark_solution_found
        return

    for each child_state of state: if valid(child_state):
        do changes

        Backtracking(child_state)

        undo changes
}