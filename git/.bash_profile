
# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
if [ -f '/c/Users/<username>/AppData/Local/mambaforge/Scripts/conda.exe' ]; then
    eval "$('/c/Users/<username>/AppData/Local/mambaforge/Scripts/conda.exe' 'shell.bash' 'hook')"
fi
# <<< conda initialize <<<

if [ -z "$SSH_AGENT_PID" ]; then
    eval $(ssh-agent)
    ssh-add ~/.ssh/id_ed25519
fi

conda activate dev-env
