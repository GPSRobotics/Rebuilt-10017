# 🤖 Git Workflow (READ BEFORE CODING)

This repository uses **branches**.  
🚫 **DO NOT PUSH TO `main`**.  
All work must be done on your own branch and submitted via a Pull Request.

## Step 0: Go into the repo
```bash
cd Rebuilt-10017  // Make sure you are inside the robot code folder
```

## Step 1: Create and switch to a new branch
```bash
git checkout -b your-branch-name  // Creates a new branch AND switches to it
```
Examples:
```bash
git checkout -b intake
git checkout -b drivetrain
git checkout -b elevator
```

## Step 2: Confirm you are NOT on main
```bash
git branch  // The branch with a * is your current branch
```
Correct example:
```
* intake
  main
```
❌ If `main` has the `*`, STOP and switch branches

## Step 3: Make code changes
// Edit files in VS Code or your editor
// Save all changes

## Step 4: Stage changes
```bash
git status  // Shows changed files
git add .   // Stages ALL changes
```

## Step 5: Commit changes
```bash
git commit -m "Short description of what you changed"  // Saves changes locally
```
Good messages:
// Fix intake motor inversion
// Add drivetrain constants
// Clean up elevator code

## Step 6: Push your branch to GitHub
```bash
git push origin your-branch-name  // Uploads your branch to GitHub
```
Example:
```bash
git push origin intake
```

## Step 7: Open a Pull Request
// 1. Go to GitHub  
// 2. Click **Compare & pull request**  
// 3. Base branch: `main`  
// 4. Compare branch: your branch  
// 5. Describe what you changed  
// 6. Submit PR  

🚫 Do NOT merge it yourself

## Step 8: Build before opening a PR
```bash
./gradlew build  // Code MUST build successfully
```
If build fails:
// ❌ Do not open a PR  
// ✅ Fix errors first

## Step 9: Update your branch with latest main
```bash
git checkout main
git pull origin main
git checkout your-branch-name
git merge main  // Keeps your branch up to date
```

## RULES (NO EXCEPTIONS)
// ❌ Never push to `main`  
// ❌ Never force push  
// ❌ Never commit broken code  
// ❌ Never work on someone else’s branch  

// ✅ One feature per branch  
// ✅ Build before PR  
// ✅ Clear commit messages  

## REMINDER
`main` must always:
// Build
// Deploy
// Not break the robot

**Treat `main` like competition code.**
