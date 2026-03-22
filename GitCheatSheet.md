  
## Git Instructions
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

### Testing
- Download this:   
        `wget https://raw.githubusercontent.com/catchorg/Catch2/devel/extras/catch_amalgamated.hpp`
- Then this:   
        `wget https://raw.githubusercontent.com/catchorg/Catch2/devel/extras/catch_amalgamated.cpp`
- Mac users: `www.idk.figureitout.com`