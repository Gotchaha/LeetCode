---
name: leetcode-prepare-cpp
description: Prepare local C++ scaffolds for LeetCode problems in this repo. Use when the user asks to prepare, create, scaffold, or set up a LeetCode C++ file for local testcase testing.
---

# LeetCode Prepare C++

## Overview

Create a `maincode/P{id}.cpp` file for a LeetCode problem so the user can work on the solution locally and quickly run example testcases. The scaffold must support local testing only; it must never solve the problem or hint at the intended approach.

## Workflow

1. Resolve the target problem from the user's number, slug, title, or URL.
   - Prefer an explicit slug or URL when present.
   - Use `mcp__leetcode.get_problem` to fetch the problem once a slug is known.
   - If only a numeric id is provided and it cannot be resolved confidently, ask for the slug or URL instead of guessing.
2. Read the returned C++ code snippet from `problem.codeSnippets` where `langSlug` is `cpp`.
3. Determine the output path as `maincode/P{questionId}.cpp`.
4. If that file already exists and is non-empty, do not overwrite it unless the user explicitly asks to replace or regenerate it.
5. Generate a local C++ file:
   - Add simple includes needed for the harness, usually starting with `#include <iostream>` and adding standard library headers only when used.
   - Keep LeetCode's helper definitions, such as `ListNode`, `TreeNode`, or `Node`, exactly equivalent to the official snippet. If LeetCode provided them inside comments, convert only those platform definitions into real C++ declarations.
   - Copy the official `class Solution` and method signature from the LeetCode C++ snippet. Leave the method body as the official empty body.
   - Add a simple `main()` that constructs one example testcase from the problem statement or `exampleTestcases`, calls the method, and prints the result in a convenient human-readable form.
6. When reasonable, compile-check the generated file without modifying the empty solution body. If compilation fails because the solution body is intentionally incomplete, report that clearly rather than filling it in.

## Hard Rules

- Do not solve the problem.
- Do not include algorithm hints, complexity comments, intended data structures, edge-case advice, or helper names that suggest the solution.
- Do not alter the `class Solution` implementation beyond preserving the official skeleton and making syntax valid locally.
- Do not generate expected-output functions or reference implementations.
- Do not submit or run code through LeetCode. This skill prepares local files only.
- Keep generated testcase code practical and lightweight. Helper functions such as `buildList`, `printList`, `buildTree`, or `printVector` are allowed when they only construct or display testcase data.

## Main Function Guidance

The `main()` is a scratchpad for the user to test LeetCode examples locally. Prefer clarity over reusable architecture.

- For scalar, string, vector, or matrix inputs, construct values directly.
- For linked lists or trees, use tiny construction and print helpers if direct construction would be noisy.
- For multiple arguments, match the official method parameter order.
- For returned pointers or containers, print the observable value, not object addresses.
- For design-class, interactive, database, shell, concurrency, or unusually complex harness problems, create the official skeleton and a best-effort minimal harness. If a faithful harness would be over-engineered, leave a short neutral TODO in `main()` such as `// Add local testcase setup here.`.

## Output Style

- Follow the repo convention `maincode/P{id}.cpp`.
- Use ASCII unless the existing file context clearly requires otherwise.
- Keep comments minimal and neutral. Comments may explain local harness helpers, but must not explain the solution.
- After creating the file, summarize the problem id, path, testcase chosen, and whether a compile-check was run.
