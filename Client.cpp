#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#pragma comment (lib,"ws2_32.lib")
using namespace std;

int main() {
	char buff[1024] = {0}, a[15] = {0};
	int b;
	string s, command[] = {"stop"};
end1:
	cout << "�����IP��ַ��";
	cin >> a;
	cout << "�˿ںţ�";
	cin >> b;
	cout << "�ȴ�����" << endl;
end:
	//��������Ȩ��
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//����socket IPV4:Af_INET IPV6:Af_INET6 TCP
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	//ָ���˿ںź�IP��ַ
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(b);
	local.sin_addr.S_un.S_addr = inet_addr(a);

	connect(sock, (struct sockaddr *)&local, sizeof(struct sockaddr_in));

	recv(sock, buff, 1024, 0);//����
	for (int i = 0; i < 1024; i++) {
		if (buff[i] == 0) {
			goto end;
		} else {
			break;
		}
	}

	cout << "���ӳɹ�" << endl;

	//���ӳɹ�
	while (1) {
		memset(buff, 0, 1024);//���
		recv(sock, buff, 1024, 0);//����
		s = (buff);
		if (s.find(command[0]) != string::npos) {
			cout << "�����ѶϿ�" << endl;
			goto end1;
		}
		printf("%s\n", buff);
	}

	return 0;
}