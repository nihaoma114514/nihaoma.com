#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#pragma comment (lib,"ws2_32.lib")
using namespace std;

int main() {
	char a[63] = {0};
	int b;
	string s, command[] = {"stop"};
end:
	cout << "�������ӵ�IP��";
	cin >> a;
	cout << "�˿ںţ�";
	cin >> b;
	cout << "�ȴ�����" << endl;
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

	//��socket,IP��ַ�Ͷ˿ں�
	bind(sock, (struct sockaddr *)&local, sizeof(struct sockaddr_in));

	//����socket
	listen(sock, 10);

	SOCKET sockfd = accept(sock, NULL, NULL);

	char buff[1024] = {1};
	send(sockfd, buff, strlen(buff), 0);//����

	//�������
	cout << "���ӳɹ�" << endl;

	while (1) {
		memset(buff, 0, 1024);//���
		printf("�����룺");
		scanf("%s", buff);
		s = (buff);
		if (s.find(command[0]) != string::npos) {
			cout << "�����ѶϿ�" << endl;
			send(sockfd, buff, strlen(buff), 0);//����
			send(sockfd, buff, strlen(buff), 0);//����
			goto end;
		}
		send(sockfd, buff, strlen(buff), 0);//����
		printf("���ͳɹ�\n");
	}

	return 0;
}
