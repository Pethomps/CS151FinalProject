# Git Instructions
##### Make a copy of the Github repository
1. Run this command in your CLI: `git clone https://github.com/Pethomps/CS151FinalProject.git finalProject`
2. Move into the new folder/directory: `cd finalProject`

##### Make a branch 
1. Create branch: `git checkout -b [new branch]`
2. Move into a branch: `git checkout [branch name]` 
3. Make changes to anything and everything 
4. Stage your changes: `git add [filename]` or `git add .`
5. Commit to your changes: `git commit -m "message"`

##### Ready to send your changes back to Github?
5. Connect new branch to Github repository: `git push --set-upstream origin [new branch]`
6. Stage anymore changes: `git add [filename]` or `git add .`
7. Commit staged changes: `git commit -m "message"`
8. Send your changes to Github: `git push`
---  
### Helpful Lines
- Show all local branches: `git branch`    
- Show current branch changes (unstaged, staged, committed): `git status`  
- Remove a file tracked by Git: `git rm --cached <file>`  
- Remove a folder tracked by Git: `git rm -r --cached <folder>`  
- Show local branches plus how/if each is connected "upstream": `git branch -vv`  
  
Example:
```
main       abc1234 [origin/main] some commit message
newBranch  def5678 [origin/newBranch] your commit message
```
###### `origin` is the "remote" (ie. Github)



--- 
## More (adapted from Grok)  
---  
### My favorites:  
`git stash` — Temporarily hide your uncommitted changes (useful before pulling).
`git stash pop` to bring them back.
`git branch -d <branch>` to delete.
`git fetch` — Downloads latest changes from GitHub without merging them into your branch. Safe way to "see what's coming."

1. The rest of it:
`git checkout --theirs <file>`
→ Takes the incoming version (from the PR or the branch you're pulling/merging). This is what you want when you want all their changes.
`git checkout --ours <file>`
→ Takes the current version (what's already in your branch/repo right now). Use this if you want to keep your side instead.  
After using either of the above on a conflicted file:
`git add <file>` (or `git add .` for all). Then git commit to finish the merge (Git will suggest a default message for merge commits).

### Bulk / one-liner versions for when there are lots of conflicts:

To accept all incoming changes during a merge:
- `git merge -X theirs <branch>` (or `git merge --strategy-option theirs`)
To accept all current changes (keep your branch's version):
- `git merge -X ours <branch>`
For git pull with auto-accept incoming:
- `git pull -X theirs`
(This is very handy if you're okay overwriting with remote changes.)
To abort a messy merge or rebase and go back:
- `git merge --abort` or `git rebase --abort`

### Pro tip for many conflicts at once:
Run this to see all conflicted files:
`git status`
Then you can do something like:
`git checkout --theirs $(git ls-files -u | cut -f2 | sort -u)` (takes incoming on everything conflicted).
Important note on "ours" vs "theirs":
During a normal merge, `--ours` = your current branch, `--theirs` = the incoming branch/PR.
During a rebase, they flip -- `--theirs` = your current branch,  `--ours` = the incoming branch/PR (always check git status to see what's happening).


2. Seeing What's Happening (essential for avoiding panic)
### These help you understand the state before/after pulls, pushes, or conflicts:

`git status` — Your best friend. Shows modified files, conflicts, what’s staged, what branch you're on, etc. Run this constantly.
`git diff` — Shows unstaged changes (what you've edited but not yet added).
`git diff --staged` — Shows what you've git added and is ready to commit.
`git diff HEAD` — Shows all changes (staged + unstaged) compared to the last commit.
`git log` — Shows commit history. Add `--oneline --graph` for a nicer view: `git log --oneline --graph --all`
`git fetch` — Downloads latest changes from GitHub without merging them into your branch. Safe way to "see what's coming."
`git branch` -a — Lists all branches (local and remote).


3. Pulling Changes (getting your teammates' work)

`git pull` — Fetches + merges (default). Can cause conflicts.
`git pull --rebase` — Fetches and rebases your work on top (cleaner history, preferred by many teams). Fewer weird merge commits.
`git pull origin main` (or whatever branch) — Explicit version.

##### After pulling, always run git status to see if conflicts appeared.


4. Pushing Your Changes

`git push` — Pushes your committed changes to the remote (GitHub) branch you're tracking.
`git push -u origin <branch-name>` — First-time push (sets upstream tracking so future git push works without typing the branch).
`git push --force-with-lease` — Safer version of force push (only if you really need to rewrite history — avoid on shared branches if possible).

5. Basic Everyday Workflow Commands

`git add <file>` or `git add .` — Stage changes.
`git commit -m "Your message"` — Commit staged changes.
`git switch <branch>` or `git checkout <branch>` — Switch branches (modern Git prefers switch).
`git branch` — List local branches.
`git branch -d <branch>` to delete.
`git stash` — Temporarily hide your uncommitted changes (useful before pulling).
`git stash pop` to bring them back.

### Recommended Safe Workflow for Group Projects

git fetch → see what's new on GitHub.
git status → check your own changes.
git pull --rebase origin main (or the target branch).
If conflicts: use --theirs / --ours as needed, then git add and git rebase --continue.
Finish your work, git add, git commit, git push.

---  


### Testing
- Download this:   
        `wget https://raw.githubusercontent.com/catchorg/Catch2/devel/extras/catch_amalgamated.hpp`
- Then this:   
        `wget https://raw.githubusercontent.com/catchorg/Catch2/devel/extras/catch_amalgamated.cpp`
- Mac users: `www.idk.figureitout.com`