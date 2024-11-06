#ifndef SECURITY_H
#define SECURITY_H

void login();
void log_error(const char *error_message);
int credentials(const char *username, const char *password);

#endif
