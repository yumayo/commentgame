#pragma once
#include "../Object/MoveObject.h"
#include "../Share/Property/PropertySystem.h"

class CharacterBase : public MoveObject {
public:


	CharacterBase(Vec2f _pos, Vec2f _size);

	WritableP<float> gravity;
	WritableP<float> gravity_max;

protected:
	void vector();
	void fall();
private:

	float gravity_ = 0.3f;
	float gravity_max_ = 20;

private: // �A�j���[�V����
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

	std::vector<Pattern> patterns;
	std::vector<Action> actions;
	Chara chara;

	void drawPattern(const Vec2f& pos_,
					 const int& index_,
					 const Texture& tex_);
	void drawAction(const Vec2f& pos_,
					const int& action_index_, const int& frame_index_,
					const Texture& tex_);
	void changeCharaAction(const int& action_index_);
protected: 

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

};