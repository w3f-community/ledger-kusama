/*******************************************************************************
*  (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM 0
#define PD_CALL_BABE 1
#define PD_CALL_TIMESTAMP 2
#define PD_CALL_INDICES 3
#define PD_CALL_BALANCES 4
#define PD_CALL_AUTHORSHIP 5
#define PD_CALL_STAKING 6
#define PD_CALL_OFFENCES 7
#define PD_CALL_SESSION 8
#define PD_CALL_GRANDPA 10
#define PD_CALL_IMONLINE 11
#define PD_CALL_AUTHORITYDISCOVERY 12
#define PD_CALL_DEMOCRACY 13
#define PD_CALL_COUNCIL 14
#define PD_CALL_TECHNICALCOMMITTEE 15
#define PD_CALL_ELECTIONSPHRAGMEN 16
#define PD_CALL_TECHNICALMEMBERSHIP 17
#define PD_CALL_TREASURY 18
#define PD_CALL_CLAIMS 19
#define PD_CALL_UTILITY 24
#define PD_CALL_IDENTITY 25
#define PD_CALL_SOCIETY 26
#define PD_CALL_RECOVERY 27
#define PD_CALL_VESTING 28
#define PD_CALL_SCHEDULER 29
#define PD_CALL_PROXY 30
#define PD_CALL_MULTISIG 31

#define PD_CALL_SYSTEM_FILL_BLOCK 0
typedef struct {
    pd_Perbill_t _ratio;
} pd_system_fill_block_t;

#define PD_CALL_SYSTEM_REMARK 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_t;

#define PD_CALL_SYSTEM_SET_CODE 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG 5
typedef struct {
    pd_OptionChangesTrieConfiguration_t changes_trie_config;
} pd_system_set_changes_trie_config_t;

#define PD_CALL_SYSTEM_SET_STORAGE 6
typedef struct {
    pd_VecKeyValue_t items;
} pd_system_set_storage_t;

#define PD_CALL_SYSTEM_KILL_STORAGE 7
typedef struct {
    pd_VecKey_t keys;
} pd_system_kill_storage_t;

#define PD_CALL_SYSTEM_KILL_PREFIX 8
typedef struct {
    pd_Key_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_t;

#define PD_CALL_SYSTEM_SUICIDE 9
typedef struct {
} pd_system_suicide_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION 0
typedef struct {
    pd_EquivocationProof_t equivocation_proof;
    pd_KeyOwnerProof_t key_owner_proof;
} pd_babe_report_equivocation_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED 1
typedef struct {
    pd_EquivocationProof_t equivocation_proof;
    pd_KeyOwnerProof_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_t;

#define PD_CALL_TIMESTAMP_SET 0
typedef struct {
    pd_CompactMoment_t now;
} pd_timestamp_set_t;

#define PD_CALL_INDICES_CLAIM 0
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_claim_t;

#define PD_CALL_INDICES_TRANSFER 1
typedef struct {
    pd_AccountId_t new_;
    pd_AccountIndex_t index;
} pd_indices_transfer_t;

#define PD_CALL_INDICES_FREE 2
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_free_t;

#define PD_CALL_INDICES_FORCE_TRANSFER 3
typedef struct {
    pd_AccountId_t new_;
    pd_AccountIndex_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_t;

#define PD_CALL_INDICES_FREEZE 4
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_freeze_t;

#define PD_CALL_BALANCES_TRANSFER 0
typedef struct {
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_t;

#define PD_CALL_BALANCES_SET_BALANCE 1
typedef struct {
    pd_LookupSource_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER 2
typedef struct {
    pd_LookupSource_t source;
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE 3
typedef struct {
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_keep_alive_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_t;

#define PD_CALL_STAKING_BOND 0
typedef struct {
    pd_LookupSource_t controller;
    pd_CompactBalanceOf_t value;
    pd_RewardDestination_t payee;
} pd_staking_bond_t;

#define PD_CALL_STAKING_BOND_EXTRA 1
typedef struct {
    pd_CompactBalanceOf_t max_additional;
} pd_staking_bond_extra_t;

#define PD_CALL_STAKING_UNBOND 2
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_unbond_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_t;

#define PD_CALL_STAKING_VALIDATE 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_t;

#define PD_CALL_STAKING_NOMINATE 5
typedef struct {
    pd_VecLookupSource_t targets;
} pd_staking_nominate_t;

#define PD_CALL_STAKING_CHILL 6
typedef struct {
} pd_staking_chill_t;

#define PD_CALL_STAKING_SET_PAYEE 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_t;

#define PD_CALL_STAKING_SET_CONTROLLER 8
typedef struct {
    pd_LookupSource_t controller;
} pd_staking_set_controller_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS 12
typedef struct {
} pd_staking_force_no_eras_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA 13
typedef struct {
} pd_staking_force_new_era_t;

#define PD_CALL_STAKING_SET_INVULNERABLES 14
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE 15
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS 16
typedef struct {
} pd_staking_force_new_era_always_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH 17
typedef struct {
    pd_EraIndex_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_t;

#define PD_CALL_STAKING_REBOND 19
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_rebond_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH 20
typedef struct {
    pd_CompactEraIndex_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_t;

#define PD_CALL_STAKING_REAP_STASH 21
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION 22
typedef struct {
    pd_VecValidatorIndex_t winners;
    pd_CompactAssignments_t compact;
    pd_ElectionScore_t score;
    pd_EraIndex_t era;
    pd_ElectionSize_t size;
} pd_staking_submit_election_solution_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_UNSIGNED 23
typedef struct {
    pd_VecValidatorIndex_t winners;
    pd_CompactAssignments_t compact;
    pd_ElectionScore_t score;
    pd_EraIndex_t era;
    pd_ElectionSize_t size;
} pd_staking_submit_election_solution_unsigned_t;

#define PD_CALL_SESSION_SET_KEYS 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_t;

#define PD_CALL_SESSION_PURGE_KEYS 1
typedef struct {
} pd_session_purge_keys_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION 0
typedef struct {
    pd_EquivocationProof_t equivocation_proof;
    pd_KeyOwnerProof_t key_owner_proof;
} pd_grandpa_report_equivocation_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED 1
typedef struct {
    pd_EquivocationProof_t equivocation_proof;
    pd_KeyOwnerProof_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_t;

#define PD_CALL_GRANDPA_NOTE_STALLED 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_t;

#define PD_CALL_IMONLINE_HEARTBEAT 0
typedef struct {
    pd_Heartbeat_t heartbeat;
    pd_Signature_t _signature;
} pd_imonline_heartbeat_t;

#define PD_CALL_DEMOCRACY_PROPOSE 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalanceOf_t value;
} pd_democracy_propose_t;

#define PD_CALL_DEMOCRACY_SECOND 1
typedef struct {
    pd_CompactPropIndex_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_t;

#define PD_CALL_DEMOCRACY_VOTE 2
typedef struct {
    pd_CompactReferendumIndex_t ref_index;
    pd_AccountVote_t vote;
} pd_democracy_vote_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL 3
typedef struct {
    pd_ReferendumIndex_t ref_index;
} pd_democracy_emergency_cancel_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM 9
typedef struct {
    pd_CompactReferendumIndex_t ref_index;
} pd_democracy_cancel_referendum_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED 10
typedef struct {
    pd_ReferendumIndex_t which;
} pd_democracy_cancel_queued_t;

#define PD_CALL_DEMOCRACY_DELEGATE 11
typedef struct {
    pd_AccountId_t to;
    pd_Conviction_t conviction;
    pd_BalanceOf_t balance;
} pd_democracy_delegate_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE 12
typedef struct {
} pd_democracy_undelegate_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS 13
typedef struct {
} pd_democracy_clear_public_proposals_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_t;

#define PD_CALL_DEMOCRACY_UNLOCK 19
typedef struct {
    pd_AccountId_t target;
} pd_democracy_unlock_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE 20
typedef struct {
    pd_ReferendumIndex_t index;
} pd_democracy_remove_vote_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE 21
typedef struct {
    pd_AccountId_t target;
    pd_ReferendumIndex_t index;
} pd_democracy_remove_other_vote_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_t index;
} pd_democracy_enact_proposal_t;

#define PD_CALL_DEMOCRACY_BLACKLIST 23
typedef struct {
    pd_Hash_t proposal_hash;
    pd_OptionReferendumIndex_t maybe_ref_index;
} pd_democracy_blacklist_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL 24
typedef struct {
    pd_CompactPropIndex_t prop_index;
} pd_democracy_cancel_proposal_t;

#define PD_CALL_COUNCIL_SET_MEMBERS 0
typedef struct {
    pd_VecAccountId_t new_members;
    pd_OptionAccountId_t prime;
    pd_MemberCount_t old_count;
} pd_council_set_members_t;

#define PD_CALL_COUNCIL_VOTE 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_t index;
    pd_bool_t approve;
} pd_council_vote_t;

#define PD_CALL_COUNCIL_CLOSE 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_t index;
    pd_CompactWeight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS 0
typedef struct {
    pd_VecAccountId_t new_members;
    pd_OptionAccountId_t prime;
    pd_MemberCount_t old_count;
} pd_technicalcommittee_set_members_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_t index;
    pd_CompactWeight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_t;

#define PD_CALL_ELECTIONSPHRAGMEN_VOTE 0
typedef struct {
    pd_VecAccountId_t votes;
    pd_CompactBalanceOf_t value;
} pd_electionsphragmen_vote_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REMOVE_VOTER 1
typedef struct {
} pd_electionsphragmen_remove_voter_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REPORT_DEFUNCT_VOTER 2
typedef struct {
    pd_DefunctVoter_t defunct;
} pd_electionsphragmen_report_defunct_voter_t;

#define PD_CALL_ELECTIONSPHRAGMEN_SUBMIT_CANDIDACY 3
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_electionsphragmen_submit_candidacy_t;

#define PD_CALL_ELECTIONSPHRAGMEN_RENOUNCE_CANDIDACY 4
typedef struct {
    pd_Renouncing_t renouncing;
} pd_electionsphragmen_renounce_candidacy_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REMOVE_MEMBER 5
typedef struct {
    pd_LookupSource_t who;
    pd_bool_t has_replacement;
} pd_electionsphragmen_remove_member_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER 0
typedef struct {
    pd_AccountId_t who;
} pd_technicalmembership_add_member_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER 1
typedef struct {
    pd_AccountId_t who;
} pd_technicalmembership_remove_member_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER 2
typedef struct {
    pd_AccountId_t remove;
    pd_AccountId_t add;
} pd_technicalmembership_swap_member_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS 3
typedef struct {
    pd_VecAccountId_t members;
} pd_technicalmembership_reset_members_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY 4
typedef struct {
    pd_AccountId_t new_;
} pd_technicalmembership_change_key_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME 5
typedef struct {
    pd_AccountId_t who;
} pd_technicalmembership_set_prime_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME 6
typedef struct {
} pd_technicalmembership_clear_prime_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_LookupSource_t beneficiary;
} pd_treasury_propose_spend_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL 1
typedef struct {
    pd_CompactProposalIndex_t proposal_id;
} pd_treasury_reject_proposal_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL 2
typedef struct {
    pd_CompactProposalIndex_t proposal_id;
} pd_treasury_approve_proposal_t;

#define PD_CALL_TREASURY_REPORT_AWESOME 3
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_t who;
} pd_treasury_report_awesome_t;

#define PD_CALL_TREASURY_RETRACT_TIP 4
typedef struct {
    pd_Hash_t hash;
} pd_treasury_retract_tip_t;

#define PD_CALL_TREASURY_TIP_NEW 5
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_t who;
    pd_CompactBalanceOf_t tip_value;
} pd_treasury_tip_new_t;

#define PD_CALL_TREASURY_TIP 6
typedef struct {
    pd_Hash_t hash;
    pd_CompactBalanceOf_t tip_value;
} pd_treasury_tip_t;

#define PD_CALL_TREASURY_CLOSE_TIP 7
typedef struct {
    pd_Hash_t hash;
} pd_treasury_close_tip_t;

#define PD_CALL_TREASURY_PROPOSE_BOUNTY 8
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_Bytes_t description;
} pd_treasury_propose_bounty_t;

#define PD_CALL_TREASURY_APPROVE_BOUNTY 9
typedef struct {
    pd_CompactProposalIndex_t bounty_id;
} pd_treasury_approve_bounty_t;

#define PD_CALL_TREASURY_PROPOSE_CURATOR 10
typedef struct {
    pd_CompactProposalIndex_t bounty_id;
    pd_LookupSource_t curator;
    pd_CompactBalanceOf_t fee;
} pd_treasury_propose_curator_t;

#define PD_CALL_TREASURY_UNASSIGN_CURATOR 11
typedef struct {
    pd_CompactProposalIndex_t bounty_id;
} pd_treasury_unassign_curator_t;

#define PD_CALL_TREASURY_ACCEPT_CURATOR 12
typedef struct {
    pd_CompactProposalIndex_t bounty_id;
} pd_treasury_accept_curator_t;

#define PD_CALL_TREASURY_AWARD_BOUNTY 13
typedef struct {
    pd_CompactProposalIndex_t bounty_id;
    pd_LookupSource_t beneficiary;
} pd_treasury_award_bounty_t;

#define PD_CALL_TREASURY_CLAIM_BOUNTY 14
typedef struct {
    pd_CompactBountyIndex_t bounty_id;
} pd_treasury_claim_bounty_t;

#define PD_CALL_TREASURY_CLOSE_BOUNTY 15
typedef struct {
    pd_CompactBountyIndex_t bounty_id;
} pd_treasury_close_bounty_t;

#define PD_CALL_TREASURY_EXTEND_BOUNTY_EXPIRY 16
typedef struct {
    pd_CompactBountyIndex_t bounty_id;
    pd_Bytes_t _remark;
} pd_treasury_extend_bounty_expiry_t;

#define PD_CALL_CLAIMS_CLAIM 0
typedef struct {
    pd_AccountId_t dest;
    pd_EcdsaSignature_t ethereum_signature;
} pd_claims_claim_t;

#define PD_CALL_CLAIMS_MINT_CLAIM 1
typedef struct {
    pd_EthereumAddress_t who;
    pd_BalanceOf_t value;
    pd_OptionTupleBalanceOfBalanceOfBlockNumber_t vesting_schedule;
    pd_OptionStatementKind_t statement;
} pd_claims_mint_claim_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST 2
typedef struct {
    pd_AccountId_t dest;
    pd_EcdsaSignature_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_t;

#define PD_CALL_CLAIMS_ATTEST 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM 4
typedef struct {
    pd_EthereumAddress_t old;
    pd_EthereumAddress_t new_;
    pd_OptionAccountId_t maybe_preclaim;
} pd_claims_move_claim_t;

#define PD_CALL_UTILITY_BATCH 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_t;

#define PD_CALL_UTILITY_BATCH_ALL 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR 0
typedef struct {
    pd_AccountId_t account;
} pd_identity_add_registrar_t;

#define PD_CALL_IDENTITY_SET_IDENTITY 1
typedef struct {
    pd_IdentityInfo_t info;
} pd_identity_set_identity_t;

#define PD_CALL_IDENTITY_SET_SUBS 2
typedef struct {
    pd_VecTupleAccountIdData_t subs;
} pd_identity_set_subs_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY 3
typedef struct {
} pd_identity_clear_identity_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT 4
typedef struct {
    pd_CompactRegistrarIndex_t reg_index;
    pd_CompactBalanceOf_t max_fee;
} pd_identity_request_judgement_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST 5
typedef struct {
    pd_RegistrarIndex_t reg_index;
} pd_identity_cancel_request_t;

#define PD_CALL_IDENTITY_SET_FEE 6
typedef struct {
    pd_CompactRegistrarIndex_t index;
    pd_CompactBalanceOf_t fee;
} pd_identity_set_fee_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID 7
typedef struct {
    pd_CompactRegistrarIndex_t index;
    pd_AccountId_t new_;
} pd_identity_set_account_id_t;

#define PD_CALL_IDENTITY_SET_FIELDS 8
typedef struct {
    pd_CompactRegistrarIndex_t index;
    pd_IdentityFields_t fields;
} pd_identity_set_fields_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT 9
typedef struct {
    pd_CompactRegistrarIndex_t reg_index;
    pd_LookupSource_t target;
    pd_Judgement_t judgement;
} pd_identity_provide_judgement_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY 10
typedef struct {
    pd_LookupSource_t target;
} pd_identity_kill_identity_t;

#define PD_CALL_IDENTITY_ADD_SUB 11
typedef struct {
    pd_LookupSource_t sub;
    pd_Data_t data;
} pd_identity_add_sub_t;

#define PD_CALL_IDENTITY_RENAME_SUB 12
typedef struct {
    pd_LookupSource_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_t;

#define PD_CALL_IDENTITY_REMOVE_SUB 13
typedef struct {
    pd_LookupSource_t sub;
} pd_identity_remove_sub_t;

#define PD_CALL_IDENTITY_QUIT_SUB 14
typedef struct {
} pd_identity_quit_sub_t;

#define PD_CALL_SOCIETY_BID 0
typedef struct {
    pd_BalanceOf_t value;
} pd_society_bid_t;

#define PD_CALL_SOCIETY_UNBID 1
typedef struct {
    pd_u32_t pos;
} pd_society_unbid_t;

#define PD_CALL_SOCIETY_VOUCH 2
typedef struct {
    pd_AccountId_t who;
    pd_BalanceOf_t value;
    pd_BalanceOf_t tip;
} pd_society_vouch_t;

#define PD_CALL_SOCIETY_UNVOUCH 3
typedef struct {
    pd_u32_t pos;
} pd_society_unvouch_t;

#define PD_CALL_SOCIETY_VOTE 4
typedef struct {
    pd_LookupSource_t candidate;
    pd_bool_t approve;
} pd_society_vote_t;

#define PD_CALL_SOCIETY_DEFENDER_VOTE 5
typedef struct {
    pd_bool_t approve;
} pd_society_defender_vote_t;

#define PD_CALL_SOCIETY_PAYOUT 6
typedef struct {
} pd_society_payout_t;

#define PD_CALL_SOCIETY_FOUND 7
typedef struct {
    pd_AccountId_t founder;
    pd_u32_t max_members;
    pd_Bytes_t rules;
} pd_society_found_t;

#define PD_CALL_SOCIETY_UNFOUND 8
typedef struct {
} pd_society_unfound_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_MEMBER 9
typedef struct {
    pd_AccountId_t who;
    pd_bool_t forgive;
} pd_society_judge_suspended_member_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_CANDIDATE 10
typedef struct {
    pd_AccountId_t who;
    pd_Judgement_t judgement;
} pd_society_judge_suspended_candidate_t;

#define PD_CALL_SOCIETY_SET_MAX_MEMBERS 11
typedef struct {
    pd_u32_t max;
} pd_society_set_max_members_t;

#define PD_CALL_RECOVERY_AS_RECOVERED 0
typedef struct {
    pd_AccountId_t account;
    pd_Call_t call;
} pd_recovery_as_recovered_t;

#define PD_CALL_RECOVERY_SET_RECOVERED 1
typedef struct {
    pd_AccountId_t lost;
    pd_AccountId_t rescuer;
} pd_recovery_set_recovered_t;

#define PD_CALL_RECOVERY_CREATE_RECOVERY 2
typedef struct {
    pd_VecAccountId_t friends;
    pd_u16_t threshold;
    pd_BlockNumber_t delay_period;
} pd_recovery_create_recovery_t;

#define PD_CALL_RECOVERY_INITIATE_RECOVERY 3
typedef struct {
    pd_AccountId_t account;
} pd_recovery_initiate_recovery_t;

#define PD_CALL_RECOVERY_VOUCH_RECOVERY 4
typedef struct {
    pd_AccountId_t lost;
    pd_AccountId_t rescuer;
} pd_recovery_vouch_recovery_t;

#define PD_CALL_RECOVERY_CLAIM_RECOVERY 5
typedef struct {
    pd_AccountId_t account;
} pd_recovery_claim_recovery_t;

#define PD_CALL_RECOVERY_CLOSE_RECOVERY 6
typedef struct {
    pd_AccountId_t rescuer;
} pd_recovery_close_recovery_t;

#define PD_CALL_RECOVERY_REMOVE_RECOVERY 7
typedef struct {
} pd_recovery_remove_recovery_t;

#define PD_CALL_RECOVERY_CANCEL_RECOVERED 8
typedef struct {
    pd_AccountId_t account;
} pd_recovery_cancel_recovered_t;

#define PD_CALL_VESTING_VEST 0
typedef struct {
} pd_vesting_vest_t;

#define PD_CALL_VESTING_VEST_OTHER 1
typedef struct {
    pd_LookupSource_t target;
} pd_vesting_vest_other_t;

#define PD_CALL_VESTING_VESTED_TRANSFER 2
typedef struct {
    pd_LookupSource_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_vested_transfer_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER 3
typedef struct {
    pd_LookupSource_t source;
    pd_LookupSource_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_force_vested_transfer_t;

#define PD_CALL_SCHEDULER_SCHEDULE 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionPeriod_t maybe_periodic;
    pd_Priority_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_t;

#define PD_CALL_SCHEDULER_CANCEL 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED 2
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionPeriod_t maybe_periodic;
    pd_Priority_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED 3
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionPeriod_t maybe_periodic;
    pd_Priority_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_after_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER 5
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionPeriod_t maybe_periodic;
    pd_Priority_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_after_t;

#define PD_CALL_PROXY_PROXY 0
typedef struct {
    pd_AccountId_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_t;

#define PD_CALL_PROXY_ADD_PROXY 1
typedef struct {
    pd_AccountId_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_t;

#define PD_CALL_PROXY_REMOVE_PROXY 2
typedef struct {
    pd_AccountId_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_t;

#define PD_CALL_PROXY_REMOVE_PROXIES 3
typedef struct {
} pd_proxy_remove_proxies_t;

#define PD_CALL_PROXY_ANONYMOUS 4
typedef struct {
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS 5
typedef struct {
    pd_AccountId_t spawner;
    pd_ProxyType_t proxy_type;
    pd_u16_t index;
    pd_CompactBlockNumber_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_t;

#define PD_CALL_PROXY_ANNOUNCE 6
typedef struct {
    pd_AccountId_t real;
    pd_CallHashOf_t call_hash;
} pd_proxy_announce_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT 7
typedef struct {
    pd_AccountId_t real;
    pd_CallHashOf_t call_hash;
} pd_proxy_remove_announcement_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT 8
typedef struct {
    pd_AccountId_t delegate;
    pd_CallHashOf_t call_hash;
} pd_proxy_reject_announcement_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED 9
typedef struct {
    pd_AccountId_t delegate;
    pd_AccountId_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_t;

#define PD_CALL_MULTISIG_AS_MULTI 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_OpaqueCall_t call;
    pd_bool_t store_call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_u8_array_32_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_u8_array_32_t call_hash;
} pd_multisig_cancel_as_multi_t;

typedef union {
    pd_system_fill_block_t system_fill_block;
    pd_system_remark_t system_remark;
    pd_system_set_heap_pages_t system_set_heap_pages;
    pd_system_set_code_t system_set_code;
    pd_system_set_code_without_checks_t system_set_code_without_checks;
    pd_system_set_changes_trie_config_t system_set_changes_trie_config;
    pd_system_set_storage_t system_set_storage;
    pd_system_kill_storage_t system_kill_storage;
    pd_system_kill_prefix_t system_kill_prefix;
    pd_system_suicide_t system_suicide;
    pd_babe_report_equivocation_t babe_report_equivocation;
    pd_babe_report_equivocation_unsigned_t babe_report_equivocation_unsigned;
    pd_timestamp_set_t timestamp_set;
    pd_indices_claim_t indices_claim;
    pd_indices_transfer_t indices_transfer;
    pd_indices_free_t indices_free;
    pd_indices_force_transfer_t indices_force_transfer;
    pd_indices_freeze_t indices_freeze;
    pd_balances_transfer_t balances_transfer;
    pd_balances_set_balance_t balances_set_balance;
    pd_balances_force_transfer_t balances_force_transfer;
    pd_balances_transfer_keep_alive_t balances_transfer_keep_alive;
    pd_authorship_set_uncles_t authorship_set_uncles;
    pd_staking_bond_t staking_bond;
    pd_staking_bond_extra_t staking_bond_extra;
    pd_staking_unbond_t staking_unbond;
    pd_staking_withdraw_unbonded_t staking_withdraw_unbonded;
    pd_staking_validate_t staking_validate;
    pd_staking_nominate_t staking_nominate;
    pd_staking_chill_t staking_chill;
    pd_staking_set_payee_t staking_set_payee;
    pd_staking_set_controller_t staking_set_controller;
    pd_staking_set_validator_count_t staking_set_validator_count;
    pd_staking_increase_validator_count_t staking_increase_validator_count;
    pd_staking_scale_validator_count_t staking_scale_validator_count;
    pd_staking_force_no_eras_t staking_force_no_eras;
    pd_staking_force_new_era_t staking_force_new_era;
    pd_staking_set_invulnerables_t staking_set_invulnerables;
    pd_staking_force_unstake_t staking_force_unstake;
    pd_staking_force_new_era_always_t staking_force_new_era_always;
    pd_staking_cancel_deferred_slash_t staking_cancel_deferred_slash;
    pd_staking_payout_stakers_t staking_payout_stakers;
    pd_staking_rebond_t staking_rebond;
    pd_staking_set_history_depth_t staking_set_history_depth;
    pd_staking_reap_stash_t staking_reap_stash;
    pd_staking_submit_election_solution_t staking_submit_election_solution;
    pd_staking_submit_election_solution_unsigned_t staking_submit_election_solution_unsigned;
    pd_session_set_keys_t session_set_keys;
    pd_session_purge_keys_t session_purge_keys;
    pd_grandpa_report_equivocation_t grandpa_report_equivocation;
    pd_grandpa_report_equivocation_unsigned_t grandpa_report_equivocation_unsigned;
    pd_grandpa_note_stalled_t grandpa_note_stalled;
    pd_imonline_heartbeat_t imonline_heartbeat;
    pd_democracy_propose_t democracy_propose;
    pd_democracy_second_t democracy_second;
    pd_democracy_vote_t democracy_vote;
    pd_democracy_emergency_cancel_t democracy_emergency_cancel;
    pd_democracy_external_propose_t democracy_external_propose;
    pd_democracy_external_propose_majority_t democracy_external_propose_majority;
    pd_democracy_external_propose_default_t democracy_external_propose_default;
    pd_democracy_fast_track_t democracy_fast_track;
    pd_democracy_veto_external_t democracy_veto_external;
    pd_democracy_cancel_referendum_t democracy_cancel_referendum;
    pd_democracy_cancel_queued_t democracy_cancel_queued;
    pd_democracy_delegate_t democracy_delegate;
    pd_democracy_undelegate_t democracy_undelegate;
    pd_democracy_clear_public_proposals_t democracy_clear_public_proposals;
    pd_democracy_note_preimage_t democracy_note_preimage;
    pd_democracy_note_preimage_operational_t democracy_note_preimage_operational;
    pd_democracy_note_imminent_preimage_t democracy_note_imminent_preimage;
    pd_democracy_note_imminent_preimage_operational_t democracy_note_imminent_preimage_operational;
    pd_democracy_reap_preimage_t democracy_reap_preimage;
    pd_democracy_unlock_t democracy_unlock;
    pd_democracy_remove_vote_t democracy_remove_vote;
    pd_democracy_remove_other_vote_t democracy_remove_other_vote;
    pd_democracy_enact_proposal_t democracy_enact_proposal;
    pd_democracy_blacklist_t democracy_blacklist;
    pd_democracy_cancel_proposal_t democracy_cancel_proposal;
    pd_council_set_members_t council_set_members;
    pd_council_vote_t council_vote;
    pd_council_close_t council_close;
    pd_council_disapprove_proposal_t council_disapprove_proposal;
    pd_technicalcommittee_set_members_t technicalcommittee_set_members;
    pd_technicalcommittee_vote_t technicalcommittee_vote;
    pd_technicalcommittee_close_t technicalcommittee_close;
    pd_technicalcommittee_disapprove_proposal_t technicalcommittee_disapprove_proposal;
    pd_electionsphragmen_vote_t electionsphragmen_vote;
    pd_electionsphragmen_remove_voter_t electionsphragmen_remove_voter;
    pd_electionsphragmen_report_defunct_voter_t electionsphragmen_report_defunct_voter;
    pd_electionsphragmen_submit_candidacy_t electionsphragmen_submit_candidacy;
    pd_electionsphragmen_renounce_candidacy_t electionsphragmen_renounce_candidacy;
    pd_electionsphragmen_remove_member_t electionsphragmen_remove_member;
    pd_technicalmembership_add_member_t technicalmembership_add_member;
    pd_technicalmembership_remove_member_t technicalmembership_remove_member;
    pd_technicalmembership_swap_member_t technicalmembership_swap_member;
    pd_technicalmembership_reset_members_t technicalmembership_reset_members;
    pd_technicalmembership_change_key_t technicalmembership_change_key;
    pd_technicalmembership_set_prime_t technicalmembership_set_prime;
    pd_technicalmembership_clear_prime_t technicalmembership_clear_prime;
    pd_treasury_propose_spend_t treasury_propose_spend;
    pd_treasury_reject_proposal_t treasury_reject_proposal;
    pd_treasury_approve_proposal_t treasury_approve_proposal;
    pd_treasury_report_awesome_t treasury_report_awesome;
    pd_treasury_retract_tip_t treasury_retract_tip;
    pd_treasury_tip_new_t treasury_tip_new;
    pd_treasury_tip_t treasury_tip;
    pd_treasury_close_tip_t treasury_close_tip;
    pd_treasury_propose_bounty_t treasury_propose_bounty;
    pd_treasury_approve_bounty_t treasury_approve_bounty;
    pd_treasury_propose_curator_t treasury_propose_curator;
    pd_treasury_unassign_curator_t treasury_unassign_curator;
    pd_treasury_accept_curator_t treasury_accept_curator;
    pd_treasury_award_bounty_t treasury_award_bounty;
    pd_treasury_claim_bounty_t treasury_claim_bounty;
    pd_treasury_close_bounty_t treasury_close_bounty;
    pd_treasury_extend_bounty_expiry_t treasury_extend_bounty_expiry;
    pd_claims_claim_t claims_claim;
    pd_claims_mint_claim_t claims_mint_claim;
    pd_claims_claim_attest_t claims_claim_attest;
    pd_claims_attest_t claims_attest;
    pd_claims_move_claim_t claims_move_claim;
    pd_utility_batch_t utility_batch;
    pd_utility_as_derivative_t utility_as_derivative;
    pd_utility_batch_all_t utility_batch_all;
    pd_identity_add_registrar_t identity_add_registrar;
    pd_identity_set_identity_t identity_set_identity;
    pd_identity_set_subs_t identity_set_subs;
    pd_identity_clear_identity_t identity_clear_identity;
    pd_identity_request_judgement_t identity_request_judgement;
    pd_identity_cancel_request_t identity_cancel_request;
    pd_identity_set_fee_t identity_set_fee;
    pd_identity_set_account_id_t identity_set_account_id;
    pd_identity_set_fields_t identity_set_fields;
    pd_identity_provide_judgement_t identity_provide_judgement;
    pd_identity_kill_identity_t identity_kill_identity;
    pd_identity_add_sub_t identity_add_sub;
    pd_identity_rename_sub_t identity_rename_sub;
    pd_identity_remove_sub_t identity_remove_sub;
    pd_identity_quit_sub_t identity_quit_sub;
    pd_society_bid_t society_bid;
    pd_society_unbid_t society_unbid;
    pd_society_vouch_t society_vouch;
    pd_society_unvouch_t society_unvouch;
    pd_society_vote_t society_vote;
    pd_society_defender_vote_t society_defender_vote;
    pd_society_payout_t society_payout;
    pd_society_found_t society_found;
    pd_society_unfound_t society_unfound;
    pd_society_judge_suspended_member_t society_judge_suspended_member;
    pd_society_judge_suspended_candidate_t society_judge_suspended_candidate;
    pd_society_set_max_members_t society_set_max_members;
    pd_recovery_as_recovered_t recovery_as_recovered;
    pd_recovery_set_recovered_t recovery_set_recovered;
    pd_recovery_create_recovery_t recovery_create_recovery;
    pd_recovery_initiate_recovery_t recovery_initiate_recovery;
    pd_recovery_vouch_recovery_t recovery_vouch_recovery;
    pd_recovery_claim_recovery_t recovery_claim_recovery;
    pd_recovery_close_recovery_t recovery_close_recovery;
    pd_recovery_remove_recovery_t recovery_remove_recovery;
    pd_recovery_cancel_recovered_t recovery_cancel_recovered;
    pd_vesting_vest_t vesting_vest;
    pd_vesting_vest_other_t vesting_vest_other;
    pd_vesting_vested_transfer_t vesting_vested_transfer;
    pd_vesting_force_vested_transfer_t vesting_force_vested_transfer;
    pd_scheduler_schedule_t scheduler_schedule;
    pd_scheduler_cancel_t scheduler_cancel;
    pd_scheduler_schedule_named_t scheduler_schedule_named;
    pd_scheduler_cancel_named_t scheduler_cancel_named;
    pd_scheduler_schedule_after_t scheduler_schedule_after;
    pd_scheduler_schedule_named_after_t scheduler_schedule_named_after;
    pd_proxy_proxy_t proxy_proxy;
    pd_proxy_add_proxy_t proxy_add_proxy;
    pd_proxy_remove_proxy_t proxy_remove_proxy;
    pd_proxy_remove_proxies_t proxy_remove_proxies;
    pd_proxy_anonymous_t proxy_anonymous;
    pd_proxy_kill_anonymous_t proxy_kill_anonymous;
    pd_proxy_announce_t proxy_announce;
    pd_proxy_remove_announcement_t proxy_remove_announcement;
    pd_proxy_reject_announcement_t proxy_reject_announcement;
    pd_proxy_proxy_announced_t proxy_proxy_announced;
    pd_multisig_as_multi_threshold_1_t multisig_as_multi_threshold_1;
    pd_multisig_as_multi_t multisig_as_multi;
    pd_multisig_approve_as_multi_t multisig_approve_as_multi;
    pd_multisig_cancel_as_multi_t multisig_cancel_as_multi;
} pd_MethodBasic_t;

typedef struct {
    pd_CallIndex_t callIndex;
    pd_MethodBasic_t method;
    // Track proposal buffer
    const uint8_t* _ptr;
    uint16_t _len;
} pd_Proposal_t;

#define PD_CALL_COUNCIL_EXECUTE 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_t;

#define PD_CALL_COUNCIL_PROPOSE 2
typedef struct {
    pd_CompactMemberCount_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE 2
typedef struct {
    pd_CompactMemberCount_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_t;

typedef union {
    pd_council_execute_t council_execute;
    pd_council_propose_t council_propose;
    pd_technicalcommittee_execute_t technicalcommittee_execute;
    pd_technicalcommittee_propose_t technicalcommittee_propose;
} pd_MethodNested_t;

typedef union {
    pd_MethodBasic_t basic;
    pd_MethodNested_t nested;
} pd_Method_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
