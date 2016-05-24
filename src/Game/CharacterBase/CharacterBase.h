#pragma once
#include "../Object/MoveObject.h"
#include "../Share/Property/PropertySystem.h"

class CharacterBase : public MoveObject {
public:


	CharacterBase(Vec2f _pos, Vec2f _size);

	WritableP<float> gravity;
	WritableP<float> gravity_max;
	ReadOnlyP<Direction> direction;

private:

	float gravity_;
	float gravity_max_;

protected:
	Direction direction_;


protected:
	// pos�Ƀx�N�g���𑫂�
	void vector();
	// ����
	void fall();
	// x�x�N�g���ɂ���ĉ摜�𔽓]������
	void directionControl();

private:  // �A�j���[�V����
	struct Pattern {
		Vec2f offset;
		Vec2f start;
		Vec2f size;
	};
	struct Action {
		std::vector<Vec2i> frame;
		// ���̃A�N�V�����ԍ�
		int next_action;
		// �d������
		//   ���͂��󂯕t���Ȃ�
		int stiff_time;
	};
	struct Chara {
		// ���݂̃A�N�V����
		int current_action;
		// �A�N�V�����o�ߎ���(�P��:�t���[��)
		int action_time;
		// ���݂̃t���[��
		int current_frame;
		// ���݂̃t���[���̕\������(�P��:�t���[��)
		int frame_time;
	};


	int chara_direction;

	void drawPattern(const Vec2f& pos_,
					 const int& index_,
					 const Texture& tex_);
	void drawAction(const Vec2f& pos_,
					const int& action_index_, const int& frame_index_,
					const Texture& tex_);

	void patternsSizeChangePoint(const int& current_size_);
protected:
	std::vector<Pattern> patterns;
	std::vector<Action> actions;
	Chara chara;
	std::set<int> patterns_sizechange_timing;
	int patterns_size_difference;
	// Chara�̏����l�ύX
	void charaInit(const Chara& chara_);
	// �t�@�C���ǂݍ���
	void readPatterns(const std::string& filename_);
	void readAction(const std::string& filename_);

	// �L�����̕`��
	void drawChara(const Vec2f& pos_, const Texture& tex_);

	// �A�j���[�V�����̍X�V
	void updateChara();
	// �L�[���͂��󂯕t���邩���ׂ�
	bool canCharaInput();
	// �A�j���[�V�����ύX
	void changeCharaAction(const int& action_index_);


protected:


};