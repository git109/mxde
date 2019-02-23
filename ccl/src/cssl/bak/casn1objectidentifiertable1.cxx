/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: casn1objectidentifiertable.cxx
 *
 * Author: $author$
 *   Date: 1/29/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "casn1objectidentifier.hxx"

cASN1ObjectIdentifier cASN1ObjectIdentifier::m_table[e_ALL] =
{
    {"undefined",
    {0L,}},
    {"domainComponent",
    {0L,9L,2342L,19200300L,100L,1L,25L,}},
    {"Domain",
    {0L,9L,2342L,19200300L,100L,4L,13L,}},
    {"iso",
    {1L,}},
    {"rle_compression",
    {1L,1L,1L,1L,666L,1L,}},
    {"zlib_compression",
    {1L,1L,1L,1L,666L,2L,}},
    {"member_body",
    {1L,2L,}},
    {"ISO_US",
    {1L,2L,840L,}},
    {"X9_57",
    {1L,2L,840L,10040L,}},
    {"X9cm",
    {1L,2L,840L,10040L,4L,}},
    {"dsa",
    {1L,2L,840L,10040L,4L,1L,}},
    {"dsaWithSHA1",
    {1L,2L,840L,10040L,4L,3L,}},
    {"cast5_cbc",
    {1L,2L,840L,113533L,7L,66L,10L,}},
    {"pbeWithMD5AndCast5_CBC",
    {1L,2L,840L,113533L,7L,66L,12L,}},
    {"rsadsi",
    {1L,2L,840L,113549L,}},
    {"pkcs",
    {1L,2L,840L,113549L,1L,}},
    {"pkcs1",
    {1L,2L,840L,113549L,1L,1L,}},
    {"rsaEncryption",
    {1L,2L,840L,113549L,1L,1L,1L,}},
    {"md2WithRSAEncryption",
    {1L,2L,840L,113549L,1L,1L,2L,}},
    {"md5WithRSAEncryption",
    {1L,2L,840L,113549L,1L,1L,4L,}},
    {"sha1WithRSAEncryption",
    {1L,2L,840L,113549L,1L,1L,5L,}},
    {"pkcs3",
    {1L,2L,840L,113549L,1L,3L,}},
    {"dhKeyAgreement",
    {1L,2L,840L,113549L,1L,3L,1L,}},
    {"pkcs5",
    {1L,2L,840L,113549L,1L,5L,}},
    {"pbeWithMD2AndDESCBC",
    {1L,2L,840L,113549L,1L,5L,1L,}},
    {"pbeWithMD5AndDESCBC",
    {1L,2L,840L,113549L,1L,5L,3L,}},
    {"pbeWithMD2AndRC2_CBC",
    {1L,2L,840L,113549L,1L,5L,4L,}},
    {"pbeWithMD5AndRC2_CBC",
    {1L,2L,840L,113549L,1L,5L,6L,}},
    {"pbeWithSHA1AndDES_CBC",
    {1L,2L,840L,113549L,1L,5L,10L,}},
    {"pbeWithSHA1AndRC2CBC",
    {1L,2L,840L,113549L,1L,5L,11L,}},
    {"pbeWithSHA1AndRC4",
    {1L,2L,840L,113549L,1L,5L,12L,}},
    {"pbes2",
    {1L,2L,840L,113549L,1L,5L,13L,}},
    {"pbmac1",
    {1L,2L,840L,113549L,1L,5L,14L,}},
    {"pkcs7",
    {1L,2L,840L,113549L,1L,7L,}},
    {"pkcs7Data",
    {1L,2L,840L,113549L,1L,7L,1L,}},
    {"pkcs7SignedData",
    {1L,2L,840L,113549L,1L,7L,2L,}},
    {"pkcs7EnvelopedData",
    {1L,2L,840L,113549L,1L,7L,3L,}},
    {"pkcs7SignedAndEnvelopedData",
    {1L,2L,840L,113549L,1L,7L,4L,}},
    {"pkcs7DigestData",
    {1L,2L,840L,113549L,1L,7L,5L,}},
    {"pkcs7EncryptedData",
    {1L,2L,840L,113549L,1L,7L,6L,}},
    {"pkcs9",
    {1L,2L,840L,113549L,1L,9L,}},
    {"emailAddress",
    {1L,2L,840L,113549L,1L,9L,1L,}},
    {"unstructuredName",
    {1L,2L,840L,113549L,1L,9L,2L,}},
    {"contentType",
    {1L,2L,840L,113549L,1L,9L,3L,}},
    {"messageDigest",
    {1L,2L,840L,113549L,1L,9L,4L,}},
    {"signingTime",
    {1L,2L,840L,113549L,1L,9L,5L,}},
    {"countersignature",
    {1L,2L,840L,113549L,1L,9L,6L,}},
    {"challengePassword",
    {1L,2L,840L,113549L,1L,9L,7L,}},
    {"unstructuredAddress",
    {1L,2L,840L,113549L,1L,9L,8L,}},
    {"extendedCertificateAttributes",
    {1L,2L,840L,113549L,1L,9L,9L,}},
    {"ext_req",
    {1L,2L,840L,113549L,1L,9L,14L,}},
    {"SMIMECapabilities",
    {1L,2L,840L,113549L,1L,9L,15L,}},
    {"SMIME",
    {1L,2L,840L,113549L,1L,9L,16L,}},
    {"id_smime_mod",
    {1L,2L,840L,113549L,1L,9L,16L,}},
    {"id_smime_mod_cms",
    {1L,2L,840L,113549L,1L,9L,16L,0L,1L,}},
    {"id_smime_mod_ess",
    {1L,2L,840L,113549L,1L,9L,16L,0L,2L,}},
    {"id_smime_mod_oid",
    {1L,2L,840L,113549L,1L,9L,16L,0L,3L,}},
    {"id_smime_mod_msg_v3",
    {1L,2L,840L,113549L,1L,9L,16L,0L,4L,}},
    {"id_smime_mod_ets_eSignature_88",
    {1L,2L,840L,113549L,1L,9L,16L,0L,5L,}},
    {"id_smime_mod_ets_eSignature_97",
    {1L,2L,840L,113549L,1L,9L,16L,0L,6L,}},
    {"id_smime_mod_ets_eSigPolicy_88",
    {1L,2L,840L,113549L,1L,9L,16L,0L,7L,}},
    {"id_smime_mod_ets_eSigPolicy_97",
    {1L,2L,840L,113549L,1L,9L,16L,0L,8L,}},
    {"id_smime_ct",
    {1L,2L,840L,113549L,1L,9L,16L,1L,}},
    {"id_smime_ct_receipt",
    {1L,2L,840L,113549L,1L,9L,16L,1L,1L,}},
    {"id_smime_ct_authData",
    {1L,2L,840L,113549L,1L,9L,16L,1L,2L,}},
    {"id_smime_ct_publishCert",
    {1L,2L,840L,113549L,1L,9L,16L,1L,3L,}},
    {"id_smime_ct_TSTInfo",
    {1L,2L,840L,113549L,1L,9L,16L,1L,4L,}},
    {"id_smime_ct_TDTInfo",
    {1L,2L,840L,113549L,1L,9L,16L,1L,5L,}},
    {"id_smime_ct_contentInfo",
    {1L,2L,840L,113549L,1L,9L,16L,1L,6L,}},
    {"id_smime_ct_DVCSRequestData",
    {1L,2L,840L,113549L,1L,9L,16L,1L,7L,}},
    {"id_smime_ct_DVCSResponseData",
    {1L,2L,840L,113549L,1L,9L,16L,1L,8L,}},
    {"id_smime_aa",
    {1L,2L,840L,113549L,1L,9L,16L,2L,}},
    {"id_smime_aa_receiptRequest",
    {1L,2L,840L,113549L,1L,9L,16L,2L,1L,}},
    {"id_smime_aa_securityLabel",
    {1L,2L,840L,113549L,1L,9L,16L,2L,2L,}},
    {"id_smime_aa_mlExpandHistory",
    {1L,2L,840L,113549L,1L,9L,16L,2L,3L,}},
    {"id_smime_aa_contentHint",
    {1L,2L,840L,113549L,1L,9L,16L,2L,4L,}},
    {"id_smime_aa_msgSigDigest",
    {1L,2L,840L,113549L,1L,9L,16L,2L,5L,}},
    {"id_smime_aa_encapContentType",
    {1L,2L,840L,113549L,1L,9L,16L,2L,6L,}},
    {"id_smime_aa_contentIdentifier",
    {1L,2L,840L,113549L,1L,9L,16L,2L,7L,}},
    {"id_smime_aa_macValue",
    {1L,2L,840L,113549L,1L,9L,16L,2L,8L,}},
    {"id_smime_aa_equivalentLabels",
    {1L,2L,840L,113549L,1L,9L,16L,2L,9L,}},
    {"id_smime_aa_contentReference",
    {1L,2L,840L,113549L,1L,9L,16L,2L,10L,}},
    {"id_smime_aa_encrypKeyPref",
    {1L,2L,840L,113549L,1L,9L,16L,2L,11L,}},
    {"id_smime_aa_signingCertificate",
    {1L,2L,840L,113549L,1L,9L,16L,2L,12L,}},
    {"id_smime_aa_smimeEncryptCerts",
    {1L,2L,840L,113549L,1L,9L,16L,2L,13L,}},
    {"id_smime_aa_timeStampToken",
    {1L,2L,840L,113549L,1L,9L,16L,2L,14L,}},
    {"id_smime_aa_ets_sigPolicyId",
    {1L,2L,840L,113549L,1L,9L,16L,2L,15L,}},
    {"id_smime_aa_ets_commitmentType",
    {1L,2L,840L,113549L,1L,9L,16L,2L,16L,}},
    {"id_smime_aa_ets_signerLocation",
    {1L,2L,840L,113549L,1L,9L,16L,2L,17L,}},
    {"id_smime_aa_ets_signerAttr",
    {1L,2L,840L,113549L,1L,9L,16L,2L,18L,}},
    {"id_smime_aa_ets_otherSigCert",
    {1L,2L,840L,113549L,1L,9L,16L,2L,19L,}},
    {"id_smime_aa_ets_contentTimestamp",
    {1L,2L,840L,113549L,1L,9L,16L,2L,20L,}},
    {"id_smime_aa_ets_CertificateRefs",
    {1L,2L,840L,113549L,1L,9L,16L,2L,21L,}},
    {"id_smime_aa_ets_RevocationRefs",
    {1L,2L,840L,113549L,1L,9L,16L,2L,22L,}},
    {"id_smime_aa_ets_certValues",
    {1L,2L,840L,113549L,1L,9L,16L,2L,23L,}},
    {"id_smime_aa_ets_revocationValues",
    {1L,2L,840L,113549L,1L,9L,16L,2L,24L,}},
    {"id_smime_aa_ets_escTimeStamp",
    {1L,2L,840L,113549L,1L,9L,16L,2L,25L,}},
    {"id_smime_aa_ets_certCRLTimestamp",
    {1L,2L,840L,113549L,1L,9L,16L,2L,26L,}},
    {"id_smime_aa_ets_archiveTimeStamp",
    {1L,2L,840L,113549L,1L,9L,16L,2L,27L,}},
    {"id_smime_aa_signatureType",
    {1L,2L,840L,113549L,1L,9L,16L,2L,28L,}},
    {"id_smime_aa_dvcs_dvc",
    {1L,2L,840L,113549L,1L,9L,16L,2L,29L,}},
    {"id_smime_alg",
    {1L,2L,840L,113549L,1L,9L,16L,3L,}},
    {"id_smime_alg_ESDHwith3DES",
    {1L,2L,840L,113549L,1L,9L,16L,3L,1L,}},
    {"id_smime_alg_ESDHwithRC2",
    {1L,2L,840L,113549L,1L,9L,16L,3L,2L,}},
    {"id_smime_alg_3DESwrap",
    {1L,2L,840L,113549L,1L,9L,16L,3L,3L,}},
    {"id_smime_alg_RC2wrap",
    {1L,2L,840L,113549L,1L,9L,16L,3L,4L,}},
    {"id_smime_alg_ESDH",
    {1L,2L,840L,113549L,1L,9L,16L,3L,5L,}},
    {"id_smime_alg_CMS3DESwrap",
    {1L,2L,840L,113549L,1L,9L,16L,3L,6L,}},
    {"id_smime_alg_CMSRC2wrap",
    {1L,2L,840L,113549L,1L,9L,16L,3L,7L,}},
    {"id_smime_cd",
    {1L,2L,840L,113549L,1L,9L,16L,4L,}},
    {"id_smime_cd_ldap",
    {1L,2L,840L,113549L,1L,9L,16L,4L,1L,}},
    {"id_smime_spq",
    {1L,2L,840L,113549L,1L,9L,16L,5L,}},
    {"id_smime_spq_ets_sqt_uri",
    {1L,2L,840L,113549L,1L,9L,16L,5L,1L,}},
    {"id_smime_spq_ets_sqt_unotice",
    {1L,2L,840L,113549L,1L,9L,16L,5L,2L,}},
    {"id_smime_cti",
    {1L,2L,840L,113549L,1L,9L,16L,6L,}},
    {"id_smime_cti_ets_proofOfOrigin",
    {1L,2L,840L,113549L,1L,9L,16L,6L,1L,}},
    {"id_smime_cti_ets_proofOfReceipt",
    {1L,2L,840L,113549L,1L,9L,16L,6L,2L,}},
    {"id_smime_cti_ets_proofOfDelivery",
    {1L,2L,840L,113549L,1L,9L,16L,6L,3L,}},
    {"id_smime_cti_ets_proofOfSender",
    {1L,2L,840L,113549L,1L,9L,16L,6L,4L,}},
    {"id_smime_cti_ets_proofOfApproval",
    {1L,2L,840L,113549L,1L,9L,16L,6L,5L,}},
    {"id_smime_cti_ets_proofOfCreation",
    {1L,2L,840L,113549L,1L,9L,16L,6L,6L,}},
    {"friendlyName",
    {1L,2L,840L,113549L,1L,9L,20L,}},
    {"localKeyID",
    {1L,2L,840L,113549L,1L,9L,21L,}},
    {"certTypes",
    {1L,2L,840L,113549L,1L,9L,22L,}},
    {"x509Certificate",
    {1L,2L,840L,113549L,1L,9L,22L,1L,}},
    {"sdsiCertificate",
    {1L,2L,840L,113549L,1L,9L,22L,2L,}},
    {"crlTypes",
    {1L,2L,840L,113549L,1L,9L,23L,}},
    {"x509Crl",
    {1L,2L,840L,113549L,1L,9L,23L,1L,}},
    {"pkcs12",
    {1L,2L,840L,113549L,1L,12L,}},
    {"pkcs12_pbeids",
    {1L,2L,840L,113549L,1L,12L,1L,}},
    {"pbe_WithSHA1And128BitRC4",
    {1L,2L,840L,113549L,1L,12L,1L,1L,}},
    {"pbe_WithSHA1And40BitRC4",
    {1L,2L,840L,113549L,1L,12L,1L,2L,}},
    {"pbe_WithSHA1And3_Key_TripleDES_CBC",
    {1L,2L,840L,113549L,1L,12L,1L,3L,}},
    {"pbe_WithSHA1And2_Key_TripleDES_CBC",
    {1L,2L,840L,113549L,1L,12L,1L,4L,}},
    {"pbe_WithSHA1And128BitRC2_CBC",
    {1L,2L,840L,113549L,1L,12L,1L,5L,}},
    {"pbe_WithSHA1And40BitRC2_CBC",
    {1L,2L,840L,113549L,1L,12L,1L,6L,}},
    {"pkcs12_Version1",
    {1L,2L,840L,113549L,1L,12L,10L,}},
    {"pkcs12_BagIds",
    {1L,2L,840L,113549L,1L,12L,10L,1L,}},
    {"keyBag",
    {1L,2L,840L,113549L,1L,12L,10L,1L,1L,}},
    {"pkcs8ShroudedKeyBag",
    {1L,2L,840L,113549L,1L,12L,10L,1L,2L,}},
    {"certBag",
    {1L,2L,840L,113549L,1L,12L,10L,1L,3L,}},
    {"crlBag",
    {1L,2L,840L,113549L,1L,12L,10L,1L,4L,}},
    {"secretBag",
    {1L,2L,840L,113549L,1L,12L,10L,1L,5L,}},
    {"safeContentsBag",
    {1L,2L,840L,113549L,1L,12L,10L,1L,6L,}},
    {"md2",
    {1L,2L,840L,113549L,2L,2L,}},
    {"md4",
    {1L,2L,840L,113549L,2L,4L,}},
    {"md5",
    {1L,2L,840L,113549L,2L,5L,}},
    {"hmacWithSHA1",
    {1L,2L,840L,113549L,2L,7L,}},
    {"rc2cbc",
    {1L,2L,840L,113549L,3L,2L,}},
    {"rc4",
    {1L,2L,840L,113549L,3L,4L,}},
    {"desede3cbc",
    {1L,2L,840L,113549L,3L,7L,}},
    {"rc5_cbc",
    {1L,2L,840L,113549L,3L,8L,}},
    {"org",
    {1L,3L,}},
    {"dod",
    {1L,3L,6L,}},
    {"internet",
    {1L,3L,6L,1L,}},
    {"iana",
    {1L,3L,6L,1L,}},
    {"Directory",
    {1L,3L,6L,1L,1L,}},
    {"Management",
    {1L,3L,6L,1L,2L,}},
    {"Experimental",
    {1L,3L,6L,1L,3L,}},
    {"Private",
    {1L,3L,6L,1L,4L,}},
    {"Enterprises",
    {1L,3L,6L,1L,4L,1L,}},
    {"ms_ext_req",
    {1L,3L,6L,1L,4L,1L,311L,2L,1L,14L,}},
    {"ms_code_ind",
    {1L,3L,6L,1L,4L,1L,311L,2L,1L,21L,}},
    {"ms_code_com",
    {1L,3L,6L,1L,4L,1L,311L,2L,1L,22L,}},
    {"ms_ctl_sign",
    {1L,3L,6L,1L,4L,1L,311L,10L,3L,1L,}},
    {"ms_sgc",
    {1L,3L,6L,1L,4L,1L,311L,10L,3L,3L,}},
    {"ms_efs",
    {1L,3L,6L,1L,4L,1L,311L,10L,3L,4L,}},
    {"dcObject",
    {1L,3L,6L,1L,4L,1L,1466L,344L,}},
    {"idea_cbc",
    {1L,3L,6L,1L,4L,1L,188L,7L,1L,1L,2L,}},
    {"bf_cbc",
    {1L,3L,6L,1L,4L,1L,3029L,1L,2L,}},
    {"Security",
    {1L,3L,6L,1L,5L,}},
    {"id_pkix",
    {1L,3L,6L,1L,5L,5L,7L,}},
    {"id_pkix_mod",
    {1L,3L,6L,1L,5L,5L,7L,}},
    {"id_pkix1_explicit_88",
    {1L,3L,6L,1L,5L,5L,7L,0L,1L,}},
    {"id_pkix1_implicit_88",
    {1L,3L,6L,1L,5L,5L,7L,0L,2L,}},
    {"id_pkix1_explicit_93",
    {1L,3L,6L,1L,5L,5L,7L,0L,3L,}},
    {"id_pkix1_implicit_93",
    {1L,3L,6L,1L,5L,5L,7L,0L,4L,}},
    {"id_mod_crmf",
    {1L,3L,6L,1L,5L,5L,7L,0L,5L,}},
    {"id_mod_cmc",
    {1L,3L,6L,1L,5L,5L,7L,0L,6L,}},
    {"id_mod_kea_profile_88",
    {1L,3L,6L,1L,5L,5L,7L,0L,7L,}},
    {"id_mod_kea_profile_93",
    {1L,3L,6L,1L,5L,5L,7L,0L,8L,}},
    {"id_mod_cmp",
    {1L,3L,6L,1L,5L,5L,7L,0L,9L,}},
    {"id_mod_qualified_cert_88",
    {1L,3L,6L,1L,5L,5L,7L,0L,10L,}},
    {"id_mod_qualified_cert_93",
    {1L,3L,6L,1L,5L,5L,7L,0L,11L,}},
    {"id_mod_attribute_cert",
    {1L,3L,6L,1L,5L,5L,7L,0L,12L,}},
    {"id_mod_timestamp_protocol",
    {1L,3L,6L,1L,5L,5L,7L,0L,13L,}},
    {"id_mod_ocsp",
    {1L,3L,6L,1L,5L,5L,7L,0L,14L,}},
    {"id_mod_dvcs",
    {1L,3L,6L,1L,5L,5L,7L,0L,15L,}},
    {"id_mod_cmp2000",
    {1L,3L,6L,1L,5L,5L,7L,0L,16L,}},
    {"id_pe",
    {1L,3L,6L,1L,5L,5L,7L,1L,}},
    {"info_access",
    {1L,3L,6L,1L,5L,5L,7L,1L,1L,}},
    {"biometricInfo",
    {1L,3L,6L,1L,5L,5L,7L,1L,2L,}},
    {"qcStatements",
    {1L,3L,6L,1L,5L,5L,7L,1L,3L,}},
    {"ac_auditEntity",
    {1L,3L,6L,1L,5L,5L,7L,1L,4L,}},
    {"ac_targeting",
    {1L,3L,6L,1L,5L,5L,7L,1L,5L,}},
    {"aaControls",
    {1L,3L,6L,1L,5L,5L,7L,1L,6L,}},
    {"sbqp_ipAddrBlock",
    {1L,3L,6L,1L,5L,5L,7L,1L,7L,}},
    {"sbqp_autonomousSysNum",
    {1L,3L,6L,1L,5L,5L,7L,1L,8L,}},
    {"sbqp_routerIdentifier",
    {1L,3L,6L,1L,5L,5L,7L,1L,9L,}},
    {"id_qt",
    {1L,3L,6L,1L,5L,5L,7L,2L,}},
    {"id_qt_cps",
    {1L,3L,6L,1L,5L,5L,7L,2L,1L,}},
    {"id_qt_unotice",
    {1L,3L,6L,1L,5L,5L,7L,2L,2L,}},
    {"textNotice",
    {1L,3L,6L,1L,5L,5L,7L,2L,3L,}},
    {"id_kp",
    {1L,3L,6L,1L,5L,5L,7L,3L,}},
    {"server_auth",
    {1L,3L,6L,1L,5L,5L,7L,3L,1L,}},
    {"client_auth",
    {1L,3L,6L,1L,5L,5L,7L,3L,2L,}},
    {"code_sign",
    {1L,3L,6L,1L,5L,5L,7L,3L,3L,}},
    {"email_protect",
    {1L,3L,6L,1L,5L,5L,7L,3L,4L,}},
    {"ipsecEndSystem",
    {1L,3L,6L,1L,5L,5L,7L,3L,5L,}},
    {"ipsecTunnel",
    {1L,3L,6L,1L,5L,5L,7L,3L,6L,}},
    {"ipsecUser",
    {1L,3L,6L,1L,5L,5L,7L,3L,7L,}},
    {"time_stamp",
    {1L,3L,6L,1L,5L,5L,7L,3L,8L,}},
    {"OCSP_sign",
    {1L,3L,6L,1L,5L,5L,7L,3L,9L,}},
    {"dvcs",
    {1L,3L,6L,1L,5L,5L,7L,3L,10L,}},
    {"id_it",
    {1L,3L,6L,1L,5L,5L,7L,4L,}},
    {"id_it_caProtEncCert",
    {1L,3L,6L,1L,5L,5L,7L,4L,1L,}},
    {"id_it_signKeyPairTypes",
    {1L,3L,6L,1L,5L,5L,7L,4L,2L,}},
    {"id_it_encKeyPairTypes",
    {1L,3L,6L,1L,5L,5L,7L,4L,3L,}},
    {"id_it_preferredSymmAlg",
    {1L,3L,6L,1L,5L,5L,7L,4L,4L,}},
    {"id_it_caKeyUpdateInfo",
    {1L,3L,6L,1L,5L,5L,7L,4L,5L,}},
    {"id_it_currentCRL",
    {1L,3L,6L,1L,5L,5L,7L,4L,6L,}},
    {"id_it_unsupportedOIDs",
    {1L,3L,6L,1L,5L,5L,7L,4L,7L,}},
    {"id_it_subscriptionRequest",
    {1L,3L,6L,1L,5L,5L,7L,4L,8L,}},
    {"id_it_subscriptionResponse",
    {1L,3L,6L,1L,5L,5L,7L,4L,9L,}},
    {"id_it_keyPairParamReq",
    {1L,3L,6L,1L,5L,5L,7L,4L,10L,}},
    {"id_it_keyPairParamRep",
    {1L,3L,6L,1L,5L,5L,7L,4L,11L,}},
    {"id_it_revPassphrase",
    {1L,3L,6L,1L,5L,5L,7L,4L,12L,}},
    {"id_it_implicitConfirm",
    {1L,3L,6L,1L,5L,5L,7L,4L,13L,}},
    {"id_it_confirmWaitTime",
    {1L,3L,6L,1L,5L,5L,7L,4L,14L,}},
    {"id_it_origPKIMessage",
    {1L,3L,6L,1L,5L,5L,7L,4L,15L,}},
    {"id_pkip",
    {1L,3L,6L,1L,5L,5L,7L,5L,}},
    {"id_regCtrl",
    {1L,3L,6L,1L,5L,5L,7L,5L,1L,}},
    {"id_regCtrl_regToken",
    {1L,3L,6L,1L,5L,5L,7L,5L,1L,1L,}},
    {"id_regCtrl_authenticator",
    {1L,3L,6L,1L,5L,5L,7L,5L,1L,2L,}},
    {"id_regCtrl_pkiPublicationInfo",
    {1L,3L,6L,1L,5L,5L,7L,5L,1L,3L,}},
    {"id_regCtrl_pkiArchiveOptions",
    {1L,3L,6L,1L,5L,5L,7L,5L,1L,4L,}},
    {"id_regCtrl_oldCertID",
    {1L,3L,6L,1L,5L,5L,7L,5L,1L,5L,}},
    {"id_regCtrl_protocolEncrKey",
    {1L,3L,6L,1L,5L,5L,7L,5L,1L,6L,}},
    {"id_regInfo",
    {1L,3L,6L,1L,5L,5L,7L,5L,2L,}},
    {"id_regInfo_utf8Pairs",
    {1L,3L,6L,1L,5L,5L,7L,5L,2L,1L,}},
    {"id_regInfo_certReq",
    {1L,3L,6L,1L,5L,5L,7L,5L,2L,2L,}},
    {"id_alg",
    {1L,3L,6L,1L,5L,5L,7L,6L,}},
    {"id_alg_des40",
    {1L,3L,6L,1L,5L,5L,7L,6L,1L,}},
    {"id_alg_noSignature",
    {1L,3L,6L,1L,5L,5L,7L,6L,2L,}},
    {"id_alg_dh_sig_hmac_sha1",
    {1L,3L,6L,1L,5L,5L,7L,6L,3L,}},
    {"id_alg_dh_pop",
    {1L,3L,6L,1L,5L,5L,7L,6L,4L,}},
    {"id_cmc",
    {1L,3L,6L,1L,5L,5L,7L,7L,}},
    {"id_cmc_statusInfo",
    {1L,3L,6L,1L,5L,5L,7L,7L,1L,}},
    {"id_cmc_identification",
    {1L,3L,6L,1L,5L,5L,7L,7L,2L,}},
    {"id_cmc_identityProof",
    {1L,3L,6L,1L,5L,5L,7L,7L,3L,}},
    {"id_cmc_dataReturn",
    {1L,3L,6L,1L,5L,5L,7L,7L,4L,}},
    {"id_cmc_transactionId",
    {1L,3L,6L,1L,5L,5L,7L,7L,5L,}},
    {"id_cmc_senderNonce",
    {1L,3L,6L,1L,5L,5L,7L,7L,6L,}},
    {"id_cmc_recipientNonce",
    {1L,3L,6L,1L,5L,5L,7L,7L,7L,}},
    {"id_cmc_addExtensions",
    {1L,3L,6L,1L,5L,5L,7L,7L,8L,}},
    {"id_cmc_encryptedPOP",
    {1L,3L,6L,1L,5L,5L,7L,7L,9L,}},
    {"id_cmc_decryptedPOP",
    {1L,3L,6L,1L,5L,5L,7L,7L,10L,}},
    {"id_cmc_lraPOPWitness",
    {1L,3L,6L,1L,5L,5L,7L,7L,11L,}},
    {"id_cmc_getCert",
    {1L,3L,6L,1L,5L,5L,7L,7L,15L,}},
    {"id_cmc_getCRL",
    {1L,3L,6L,1L,5L,5L,7L,7L,16L,}},
    {"id_cmc_revokeRequest",
    {1L,3L,6L,1L,5L,5L,7L,7L,17L,}},
    {"id_cmc_regInfo",
    {1L,3L,6L,1L,5L,5L,7L,7L,18L,}},
    {"id_cmc_responseInfo",
    {1L,3L,6L,1L,5L,5L,7L,7L,19L,}},
    {"id_cmc_queryPending",
    {1L,3L,6L,1L,5L,5L,7L,7L,21L,}},
    {"id_cmc_popLinkRandom",
    {1L,3L,6L,1L,5L,5L,7L,7L,22L,}},
    {"id_cmc_popLinkWitness",
    {1L,3L,6L,1L,5L,5L,7L,7L,23L,}},
    {"id_cmc_confirmCertAcceptance",
    {1L,3L,6L,1L,5L,5L,7L,7L,24L,}},
    {"id_on",
    {1L,3L,6L,1L,5L,5L,7L,8L,}},
    {"id_on_personalData",
    {1L,3L,6L,1L,5L,5L,7L,8L,1L,}},
    {"id_pda",
    {1L,3L,6L,1L,5L,5L,7L,9L,}},
    {"id_pda_dateOfBirth",
    {1L,3L,6L,1L,5L,5L,7L,9L,1L,}},
    {"id_pda_placeOfBirth",
    {1L,3L,6L,1L,5L,5L,7L,9L,2L,}},
    {"id_pda_pseudonym",
    {1L,3L,6L,1L,5L,5L,7L,9L,3L,}},
    {"id_pda_gender",
    {1L,3L,6L,1L,5L,5L,7L,9L,4L,}},
    {"id_pda_countryOfCitizenship",
    {1L,3L,6L,1L,5L,5L,7L,9L,5L,}},
    {"id_pda_countryOfResidence",
    {1L,3L,6L,1L,5L,5L,7L,9L,6L,}},
    {"id_aca",
    {1L,3L,6L,1L,5L,5L,7L,10L,}},
    {"id_aca_authenticationInfo",
    {1L,3L,6L,1L,5L,5L,7L,10L,1L,}},
    {"id_aca_accessIdentity",
    {1L,3L,6L,1L,5L,5L,7L,10L,2L,}},
    {"id_aca_chargingIdentity",
    {1L,3L,6L,1L,5L,5L,7L,10L,3L,}},
    {"id_aca_group",
    {1L,3L,6L,1L,5L,5L,7L,10L,4L,}},
    {"id_aca_role",
    {1L,3L,6L,1L,5L,5L,7L,10L,5L,}},
    {"id_qcs",
    {1L,3L,6L,1L,5L,5L,7L,11L,}},
    {"id_qcs_pkixQCSyntax_v1",
    {1L,3L,6L,1L,5L,5L,7L,11L,1L,}},
    {"id_cct",
    {1L,3L,6L,1L,5L,5L,7L,12L,}},
    {"id_cct_crs",
    {1L,3L,6L,1L,5L,5L,7L,12L,1L,}},
    {"id_cct_PKIData",
    {1L,3L,6L,1L,5L,5L,7L,12L,2L,}},
    {"id_cct_PKIResponse",
    {1L,3L,6L,1L,5L,5L,7L,12L,3L,}},
    {"id_ad",
    {1L,3L,6L,1L,5L,5L,7L,48L,}},
    {"ad_OCSP",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,}},
    {"id_pkix_OCSP",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,}},
    {"id_pkix_OCSP_basic",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,1L,}},
    {"id_pkix_OCSP_Nonce",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,2L,}},
    {"id_pkix_OCSP_CrlID",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,3L,}},
    {"id_pkix_OCSP_acceptableResponses",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,4L,}},
    {"id_pkix_OCSP_noCheck",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,5L,}},
    {"id_pkix_OCSP_archiveCutoff",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,6L,}},
    {"id_pkix_OCSP_serviceLocator",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,7L,}},
    {"id_pkix_OCSP_extendedStatus",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,8L,}},
    {"id_pkix_OCSP_valid",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,9L,}},
    {"id_pkix_OCSP_path",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,10L,}},
    {"id_pkix_OCSP_trustRoot",
    {1L,3L,6L,1L,5L,5L,7L,48L,1L,11L,}},
    {"ad_ca_issuers",
    {1L,3L,6L,1L,5L,5L,7L,48L,2L,}},
    {"ad_timeStamping",
    {1L,3L,6L,1L,5L,5L,7L,48L,3L,}},
    {"ad_dvcs",
    {1L,3L,6L,1L,5L,5L,7L,48L,4L,}},
    {"SNMPv2",
    {1L,3L,6L,1L,6L,}},
    {"Mail",
    {1L,3L,6L,1L,7L,}},
    {"algorithm",
    {1L,3L,14L,3L,2L,}},
    {"md5WithRSA",
    {1L,3L,14L,3L,2L,3L,}},
    {"desecb",
    {1L,3L,14L,3L,2L,6L,}},
    {"descbc",
    {1L,3L,14L,3L,2L,7L,}},
    {"desofb",
    {1L,3L,14L,3L,2L,8L,}},
    {"descfb",
    {1L,3L,14L,3L,2L,9L,}},
    {"rsaSignature",
    {1L,3L,14L,3L,2L,11L,}},
    {"dsaEncryption",
    {1L,3L,14L,3L,2L,12L,}},
    {"dsaWithSHA",
    {1L,3L,14L,3L,2L,13L,}},
    {"shaWithRSAEncryption",
    {1L,3L,14L,3L,2L,15L,}},
    {"desede",
    {1L,3L,14L,3L,2L,17L,}},
    {"sha",
    {1L,3L,14L,3L,2L,18L,}},
    {"sha1",
    {1L,3L,14L,3L,2L,26L,}},
    {"dsaWithSHA1old",
    {1L,3L,14L,3L,2L,27L,}},
    {"sha1WithRSA",
    {1L,3L,14L,3L,2L,29L,}},
    {"ripemd160",
    {1L,3L,36L,3L,2L,1L,}},
    {"ripemd160WithRSA",
    {1L,3L,36L,3L,3L,1L,2L,}},
    {"sxnet",
    {1L,3L,101L,1L,4L,1L,}},
    {"x500",
    {2L,5L,}},
    {"x509",
    {2L,5L,4L,}},
    {"commonName",
    {2L,5L,4L,3L,}},
    {"surname",
    {2L,5L,4L,4L,}},
    {"serialNumber",
    {2L,5L,4L,5L,}},
    {"countryName",
    {2L,5L,4L,6L,}},
    {"localityName",
    {2L,5L,4L,7L,}},
    {"stateOrProvinceName",
    {2L,5L,4L,8L,}},
    {"organizationName",
    {2L,5L,4L,10L,}},
    {"organizationalUnitName",
    {2L,5L,4L,11L,}},
    {"title",
    {2L,5L,4L,12L,}},
    {"description",
    {2L,5L,4L,13L,}},
    {"name",
    {2L,5L,4L,41L,}},
    {"givenName",
    {2L,5L,4L,42L,}},
    {"initials",
    {2L,5L,4L,43L,}},
    {"uniqueIdentifier",
    {2L,5L,4L,45L,}},
    {"dnQualifier",
    {2L,5L,4L,46L,}},
    {"X500algorithms",
    {2L,5L,8L,}},
    {"rsa",
    {2L,5L,8L,1L,1L,}},
    {"mdc2withRSA",
    {2L,5L,8L,3L,100L,}},
    {"mdc2",
    {2L,5L,8L,3L,101L,}},
    {"ldce",
    {2L,5L,29L,}},
    {"subjectKeyIdentifier",
    {2L,5L,29L,14L,}},
    {"keyUsage",
    {2L,5L,29L,15L,}},
    {"privateKeyUsagePeriod",
    {2L,5L,29L,16L,}},
    {"subjectAlternativeName",
    {2L,5L,29L,17L,}},
    {"issuerAlternativeName",
    {2L,5L,29L,18L,}},
    {"basicConstraints",
    {2L,5L,29L,19L,}},
    {"crlNumber",
    {2L,5L,29L,20L,}},
    {"crl_reason",
    {2L,5L,29L,21L,}},
    {"invalidity_date",
    {2L,5L,29L,24L,}},
    {"delta_crl",
    {2L,5L,29L,27L,}},
    {"crl_distribution_points",
    {2L,5L,29L,31L,}},
    {"certificatePolicies",
    {2L,5L,29L,32L,}},
    {"authorityKeyIdentifier",
    {2L,5L,29L,35L,}},
    {"ext_key_usage",
    {2L,5L,29L,37L,}},
    {"netscape",
    {2L,16L,840L,1L,113730L,}},
    {"netscapeCertificateExtension",
    {2L,16L,840L,1L,113730L,1L,}},
    {"netscapeCertType",
    {2L,16L,840L,1L,113730L,1L,1L,}},
    {"netscapeBaseUrl",
    {2L,16L,840L,1L,113730L,1L,2L,}},
    {"netscapeRevocationUrl",
    {2L,16L,840L,1L,113730L,1L,3L,}},
    {"netscapeCARevocationUrl",
    {2L,16L,840L,1L,113730L,1L,4L,}},
    {"netscapeRenewalUrl",
    {2L,16L,840L,1L,113730L,1L,7L,}},
    {"netscapeCAPolicyUrl",
    {2L,16L,840L,1L,113730L,1L,8L,}},
    {"netscapeSSLServerName",
    {2L,16L,840L,1L,113730L,1L,12L,}},
    {"netscapeComment",
    {2L,16L,840L,1L,113730L,1L,13L,}},
    {"netscapeDataType",
    {2L,16L,840L,1L,113730L,2L,}},
    {"netscapeCertificateSequence",
    {2L,16L,840L,1L,113730L,2L,5L,}},
    {"ns_sgc",
    {2L,16L,840L,1L,113730L,4L,1L,}},
};