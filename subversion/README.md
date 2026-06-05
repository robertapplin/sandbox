# Subversion Cheatsheet

To checkout (clone) a branch:

```sh
svn checkout svn://subversion/svn/<repo>/branches/<branch>
```

To check the changes recently made:

```sh
svn status
```

To check the code difference from the last revision:

```sh
svn diff
```

To fetch and pull down remote changes to your local branch:

```sh
svn update
```

To add a *new* file to version control:

```sh
svn add <filename>
```

To delete a file from version control:

```sh
svn delete <filename>
```

To commit and push a change:

```sh
svn commit -m "Message"
```

To remove files not under version control:

```sh
svn cleanup --remove-unversioned --remove-ignored
```

To create a copy of a branch:

```sh
svn copy svn://subversion/svn/<repo>/branches/<branch> svn://subversion/svn/<repo>/branches/new-branch -m "Commit message"
```

To merge branch B into branch A:

```sh
cd branch-A
svn merge ^/branches/branch-B
svn commit -m "Message"
```
