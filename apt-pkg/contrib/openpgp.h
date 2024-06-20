/*
 * SPDX-License-Identifier: BSD-3-clause
 *
 * Copyright (C) 2024 Canonical Ltd
 */

#include <apt-pkg/string_view.h>

#include <vector>

namespace APT
{
namespace OpenPGP
{

struct PublicKey
{
   std::string algorithm;
   std::vector<std::string> uids;
   std::vector<PublicKey> subkeys;
};

class Keyring
{
   std::vector<PublicKey> publicKeys;

   public:
   APT_PUBLIC bool AddKeyFile(const char *path, APT::StringView key);
   std::vector<PublicKey>::const_iterator begin() { return publicKeys.begin(); };
   std::vector<PublicKey>::const_iterator end() { return publicKeys.end(); };
};

} // namespace OpenPGP
} // namespace APT
