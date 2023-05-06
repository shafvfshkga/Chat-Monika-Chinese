# Chat-Monika-Chinese
引用
----
    本项目使用axmol引擎制作
    https://github.com/axmolengine/axmol
    语言模型取自<br>
    https://huggingface.co/THUDM/chatglm-6b-int4
    语音模型取自<br>
    https://huggingface.co/spaces/zomehwh/vits-models
    图像资源取自<br>
    https://github.com/Monika-After-Story/MonikaModDev
环境
----
    Windows11 x64
    python3.7+
    cuda
使用方法
----
    下载Release.zip并解压
    从 https://huggingface.co/THUDM/chatglm-6b-int4/tree/main 下载pytorch_model.bin
    并将其放置在Release/chatglm-6b-in4下
    安装python，本人使用python3.9.13
    安装cuda，本人使用cuda 11.8
    下载本项目requirements.txt，在同文件夹下使用命令pip install -r requirements.txt
    建议使用wheel安装torch和torchvision，
    本人安装torch-2.0.0+cu118-cp39-cp39-win_amd64和torchvision-0.15.1+cu118-cp39-cp39-win_amd64
    配置完成后，点击ChatGLM-Monika.exe即可使用
