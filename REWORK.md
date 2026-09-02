# QMK Rework Reference

## Purpose

This file is the persistent operating reference for rebuilding and maintaining my personal QMK firmware configuration.

Codex should read this file at the beginning of any session involving this repository and use it as the authoritative project context unless I explicitly override something during the current session.

The goal is to rebuild my personal QMK configuration cleanly, using current QMK conventions, shared traditional userspace where appropriate, and keyboard-specific keymaps where necessary.

This is a rework project, not a blind restoration of the previous implementation.

---

## Repository Locations

### Active QMK Repository

`~/DEV/QMK`

This is the active QMK firmware repository and a fresh fork of:

`qmk/qmk_firmware`

### Old Reference Repository

`~/DEV/QMK-reference`

This is a preserved copy of my previous QMK fork.

Important:

- It is intentionally NOT a Git repository.
- It exists only as source-code reference material.
- Treat it as read-only.
- Never initialize Git inside it.
- Never modify, rename, move, or delete files from it unless I explicitly approve doing so.

---

## Current Environment

- OS: CachyOS / Arch-based Linux
- Development root: `~/DEV`
- QMK home: `~/DEV/QMK`
- QMK CLI installed using `uv`
- QMK CLI version at initial setup: `1.2.0`
- QMK firmware repository version at initial setup: `0.34.0`
- `qmk doctor` passes cleanly
- Required AVR and ARM build toolchains are installed
- QMK submodules are initialized and current
- Linux QMK build environment is functional

---

## Git Repository Model

The active repository uses two remotes:

- `origin` = my GitHub fork
- `upstream` = official `qmk/qmk_firmware`

Expected repository roles:

### `master`

`master` is the clean upstream-tracking baseline.

Do not use `master` for personal QMK development.

Personal changes should not be committed directly to `master`.

### `personal`

`personal` is the primary working branch for my personal QMK configuration.

Keyboard-specific feature branches may be created later if useful, but only after discussing the need for them.

---

## Git Safety Rules

Codex must follow these rules unless I explicitly override them.

1. Do not modify `master`.

2. Personal work belongs on `personal` or an explicitly approved descendant branch.

3. Do not perform any of the following without explicit approval:

   - commit
   - push
   - merge
   - rebase
   - reset
   - force push
   - branch deletion
   - tag creation or deletion
   - remote modification
   - history rewriting

4. Read-only Git inspection commands are allowed.

5. Before editing files, confirm the active branch and working-tree state.

6. Never alter `~/DEV/QMK-reference`.

---

## Previous QMK Userspace

The old repository contains shared userspace at:

`~/DEV/QMK-reference/users/blackfeather/`

Known files include:

- `blackfeather.c`
- `blackfeather.h`
- `config.h`
- `rules.mk`

There may also be keyboard-specific keymaps elsewhere under:

`~/DEV/QMK-reference/keyboards/`

There may also be files found within ~/DEV/QMK-reference/keyboards:
  /drop/alt
  /epomaker/tide65
  /preonic
  /planck
Anything found under Brad, Diane, Bradlow, Brad*, Diane*, etc should be considered mine and identified for inspection

The previous implementation should be treated as reference material, not automatically copied into the new repository.

---

## Rework Goal

Rebuild my QMK configuration using the traditional QMK shared userspace model:

`users/blackfeather/`

and keyboard-specific keymaps such as:

`keyboards/<keyboard>/keymaps/blackfeather/`

The desired architecture should make a clear distinction between:

### Shared Userspace

Functionality that genuinely applies across multiple keyboards may belong under:

`users/blackfeather/`

Examples may include:

- shared custom keycodes
- common macros
- shared helper functions
- shared layer behavior
- reusable callbacks
- shared configuration
- reusable QMK feature logic

### Keyboard-Specific Keymaps

Hardware-specific behavior should remain inside:

`keyboards/<keyboard>/keymaps/blackfeather/`

Examples may include:

- physical matrix/layout decisions
- keyboard-specific layers
- hardware-specific RGB behavior
- encoder behavior
- OLED behavior
- board-specific overrides
- features that only exist on one keyboard

Avoid unnecessary duplication, but do not force keyboard-specific behavior into shared userspace merely to reduce file count.

---

## Design Principles

Use these principles when proposing or implementing changes.

### Current QMK First

Prefer current QMK APIs, conventions, and documented patterns over code found in the old reference tree.

If the old implementation relies on deprecated, removed, or questionable behavior:

1. identify it,
2. explain the issue,
3. propose the current QMK equivalent,
4. wait for approval before implementing the replacement.

### Simplicity

Do not add abstraction merely for abstraction's sake.

Prefer code that is:

- clear
- maintainable
- easy to inspect
- easy to debug
- consistent across keyboards where appropriate

### Shared Code Deliberately

Move code into userspace only when it is actually shared or likely to be shared.

Do not create a large generic framework simply because QMK allows one.

### Preserve Intent, Not Necessarily Implementation

The old reference repository should help determine what behavior I previously wanted.

It should not dictate the new architecture.

---

## Codex Operating Rules

Before modifying relevant files, Codex should:

1. inspect the current implementation,
2. inspect relevant QMK core or documentation patterns when necessary,
3. inspect corresponding files under `~/DEV/QMK-reference`,
4. explain what the old implementation does,
5. identify any compatibility or design concerns,
6. propose the intended change,
7. receive my approval,
8. only then edit files.

Do not begin broad refactors without first discussing them.

Do not rewrite unrelated files.

Do not make cosmetic changes outside the scope of the current task unless they are necessary for correctness.

---

## Firmware Validation

Every target keyboard/keymap must eventually be validated using an actual QMK compile command.

Typical form:

`qmk compile -kb <keyboard> -km blackfeather`

Compilation success is required before a configuration is considered ready for hardware testing.

Codex must not automatically flash firmware.

Codex may provide or prepare the appropriate flash command, but I will decide when flashing occurs.

---

## Initial Rework Task

At the beginning of the rework, do not modify files.

Perform an inspection pass first.

### Initial Inspection

1. Verify the current Git branch.

2. Verify the working tree is clean or identify existing changes.

3. Verify configured remotes.

4. Inspect:

   `~/DEV/QMK-reference/users/blackfeather/`

5. Summarize what the old userspace does.

6. Search the old reference repository for code that references, includes, or depends on `blackfeather`.

7. Identify any obvious keyboard-specific keymaps associated with the old userspace.

8. Identify deprecated, obsolete, questionable, or unnecessarily complicated QMK patterns.

9. Briefly explain how current traditional QMK `users/<name>/` functionality applies to this project.

10. Propose a clean target directory architecture.

Do not write files during this inspection phase.

Stop after presenting findings and the proposed architecture so we can discuss:

- target keyboards
- desired layouts
- layers
- custom keycodes
- shared behavior
- keyboard-specific behavior
- features worth preserving
- features worth redesigning

---

## Expected Rework Process

The general project flow should be:

1. Inspect old userspace.
2. Identify old keyboard keymaps.
3. Identify the keyboards currently being rebuilt.
4. Document desired behavior for each keyboard.
5. Separate shared behavior from keyboard-specific behavior.
6. Design the new `users/blackfeather/` structure.
7. Implement shared userspace incrementally.
8. Rebuild one keyboard keymap at a time.
9. Compile after meaningful changes.
10. Resolve warnings or build failures before proceeding.
11. Hardware-test when I explicitly choose to flash.
12. Refine shared code only after real duplication or common behavior becomes apparent.
13. Document important architectural decisions in this file when appropriate.

---

## Upstream QMK Maintenance

A future project task is to establish a simple, repeatable workflow for synchronizing the repository with official QMK.

The desired relationship is:

`qmk/qmk_firmware upstream/master`
→ local `master`
→ GitHub fork `origin/master`
→ `personal` as appropriate

This workflow should prevent my fork from drifting indefinitely from upstream.

The maintenance procedure should eventually cover:

- fetching upstream changes,
- updating local `master`,
- updating `origin/master`,
- incorporating upstream changes into `personal`,
- resolving conflicts safely,
- updating submodules when required,
- running `qmk doctor`,
- compiling representative keymaps after significant QMK updates.

Do not implement or automate this workflow until the core keymap/userspace rebuild is working unless I explicitly move this task forward.

---

## Context Maintenance

This file is intended to remain useful across many Codex sessions.

When a significant project decision is made, Codex may propose an update to `REWORK.md`.

Examples include:

- finalized userspace architecture
- target keyboard list
- branch strategy changes
- naming decisions
- common layer conventions
- custom keycode conventions
- build commands
- upstream synchronization procedure
- important compatibility findings
- completed milestones
- deliberately rejected approaches

Do not silently rewrite this document.

For meaningful changes to project policy, architecture, or workflow:

1. propose the update,
2. explain why it should be recorded,
3. receive approval,
4. then update this file.

Routine progress notes do not need to be added unless they materially help future sessions.

---

## Current Project Status

Initial environment setup is complete.

Known-good state:

- fresh QMK fork created
- active repository located at `~/DEV/QMK`
- old repository preserved at `~/DEV/QMK-reference`
- old reference repository stripped of Git tracking
- QMK CLI installed with `uv`
- `qmk doctor` clean
- compiler toolchains installed
- submodules current
- upstream QMK baseline current at initial setup
- old `users/blackfeather/` source preserved for reference

Next phase:

**Inspect the old userspace and keymaps, determine the target architecture, and begin the controlled rebuild.**
