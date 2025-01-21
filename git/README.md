# Git

[Git Cheat Sheet](https://education.github.com/git-cheat-sheet-education.pdf)
[Git Config](https://developer.mantidproject.org/GitConfig.html)

## Git Alias

Defining an alias:

```sh
git config --global alias.ac '!git add A && git commit -m'
```

## Git Bisect

Running git bisect:

```sh
git bisect start HEAD v5.1.0 --
git bisect run python test_script.py
git bisect reset
```

The contents of ``test_script.py``:

```py
import sys
from mantid.simpleapi import ISISIndirectEnergyTransferWrapper


workspace = ISISIndirectEnergyTransferWrapper(InputFiles=['TOSCA26911', 'TOSCA26912', 'TOSCA26913'], Instrument="TOSCA",
                                              Analyser="graphite", Reflection="002", SpectraRange=[1, 140],
                                              RebinString='-2.5,0.015,3,-0.005,1000', SumFiles=True)

if workspace[0].getNumberHistograms() == 3:
    sys.exit(0)
else:
    sys.exit(1)
```

## Git cherry-pick

1. Use ``git log`` to find the commit sha
2. Checkout the branch you want to have the commit
3. Do ``git cherry-pick <commit_sha>``
4. Do an interative rebase to ``drop`` the commit from the branch you took the commit from.

## Git commit

[Git commit template](https://gist.github.com/lisawolderiksen/a7b99d94c92c6671181611be1641c733)

Add co-authors to a commit:

```
Co-authored-by: Thomas Hampson <thomashampson@users.noreply.github.com>
Co-authored-by: Gemma Guest <gemmaguest@users.noreply.github.com>
Co-authored-by: Rachel Baust <rbauststfc@users.noreply.github.com>
```

## Git diff

To view the differences between a ``<branch>`` and ``main``:

```sh
git diff main...<branch>
```

Compare the difference between two branches:

```sh
git diff <branch1>...<branch2>
```

# Git grep 

Grep for strings which are under source control:

```sh
git grep -n 'string' -- '*.py'
```

## Git reset

Uncommit and unstage (unadd) the last two commits. The uncommitted code is not removed and will still exist locally:

```sh
git reset HEAD~2
```

This will unstage a file:

```sh
git reset HEAD -- <file>
```

## Git revert

Create a commit which reverts the changes from a previous commit:

```sh
git revert <commit_hash>
```
